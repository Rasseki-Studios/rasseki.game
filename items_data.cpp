#include "session_data.h"
// #include "event_factory.h"
#include "mapscanner.h"
#include <algorithm>
#include <vector>

using std::vector;
using namespace SessionData;

//---------------------------------------------------------
//----------------- EventsData ----------------------------
//---------------------------------------------------------

bool EventsData::Init() {
    EventFactory eFactory;
    str path = systemData.resourcesDirectory + systemData.nextLocationName + "/events";
    eFactory.InitAll(path, currentEventList); // hardcoded just for debugging
    // using unique_ptr for two-dim array isn't a good idea though
    // std::unique_ptr<Event[][]> eventMatrix (nullptr); 
    
    eventMatrix = new std::vector<Event>** [gameData.mapHeight];
    for (int i = 0; i != gameData.mapHeight; i++) {
        eventMatrix[i] = new std::vector<Event>*;
        for (int j = 0; j != gameData.mapWidth; j++) {
        eventMatrix[i][j] = NULL;
        }
    }

    PulverizeEvents(currentEventList); 
    return true;
}

Event* EventsData::getEvent(const str key) {
    return &currentEventList.at(key);
}

Event* EventsData::getEvent(Coord point) {
    if (!surfaceData.CoordIsValid(point)) return NULL;
    if (!eventMatrix[point.x][point.y]) return NULL;
    auto ev = eventMatrix[point.x][point.y];
    if (!eventMatrix[point.x][point.y]->empty()) 
        return &eventMatrix[point.x][point.y]->front();
    else return NULL;
}

void EventsData::PulverizeEvents(std::unordered_map<str, Event>& list) {
/* 
parsing map - getting event and spraying it at the map. 
get event
add event to map
*/
    for (auto i : list) {
        Event event = i.second;
        
        int width = gameData.mapWidth;
        int height = gameData.mapHeight;

        Coord eventCenter = event.GetCoord();
        if (eventCenter.x > width || eventCenter.y > height) throw "coordinates are out of range";
        if (eventCenter.x < 0 || eventCenter.y < 0) throw "invalid coordinates";

        for (int i = eventCenter.x - event.getRadius(); i <= eventCenter.x + event.getRadius(); i++) {
            for (int j = eventCenter.y - event.getRadius(); j <= eventCenter.y + event.getRadius(); j++) {
                
                if (
                    eventCenter.y + event.getRadius() > height ||
                    eventCenter.x + event.getRadius() > width  ||
                    eventCenter.y - event.getRadius() < 0      ||
                    eventCenter.x - event.getRadius() < 0      
                ) break; //total size of event mark exceeded the map

                // if (!SurfaceMap::getSurface(eventCenter)) break;

                if (!eventMatrix[eventCenter.x][eventCenter.y]) {
                    eventMatrix[eventCenter.x][eventCenter.y] = new std::vector<Event>;
                eventMatrix[eventCenter.x][eventCenter.y]->push_back(event);
                }
                else {
                    eventMatrix[eventCenter.x][eventCenter.y]->push_back(event);  

                    std::push_heap( // SIC! that wasn't tested
                        eventMatrix[eventCenter.x][eventCenter.y]->begin(),
                        eventMatrix[eventCenter.x][eventCenter.y]->end(),
                        [](Event& a, Event& b) {
                            return a.getPriority() < b.getPriority();
                            }
                        );
                }
            }
        }
    }
}

void EventsData::RemoveFrontEvent(Coord point) {
    Event* event = getEvent(point);
    Coord center = event->GetCoord();
    int radius = event->getRadius();

    for (int i = center.x - radius ; i < center.x + radius; i++) {
        for (int j = center.y - radius ; j < center.y + radius; j++) {
            if ( surfaceData.CoordIsValid( {i, j} ) ) {
                std::pop_heap(eventMatrix[i][j]->begin(), 
                eventMatrix[i][j]->end(),
                [](Event& a, Event& b) {
                    return a.getPriority() < b.getPriority();
                } );
            };
        }
    }
}

bool EventsData::EventExists(str ID) {
    return currentEventList.count(ID);
}

//---------------------------------------------------------
//---------------- ArtifactsData --------------------------
//---------------------------------------------------------

bool ArtifactsData::Init() {
    ArtifactFactory aFactory;
    str path = systemData.resourcesDirectory + systemData.nextLocationName + "/artifacts";
    aFactory.InitAll(path, currentArtifactsList);
    return true;
}

Artifact* ArtifactsData::getArtifact(const str key) {
    return &currentArtifactsList.at(key);
}

bool ArtifactsData::ArtifactExists(str ID) {
    return currentArtifactsList.count(ID);
}

//---------------------------------------------------------
//--------------------- GameData --------------------------
//---------------------------------------------------------



//---------------------------------------------------------
//--------------------- SystemData ------------------------
//---------------------------------------------------------

SystemData::SystemData(str _nextLocationName)
: 
resourcesDirectory(":/"), 
nextLocationName(_nextLocationName), 
mapName("map") {

}