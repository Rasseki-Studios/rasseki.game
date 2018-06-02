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

/* bool EventsData::Init() {
    EventFactory eFactory;
    str path = systemData.resourcesDirectory + systemData.nextLocationName + "/events";
    eFactory.InitAll(path, currentEventList); // hardcoded just for debugging
    // using unique_ptr for two-dim array isn't a good idea though
    // std::unique_ptr<Event[][]> eventMatrix (nullptr); 
    
    /* 
    eventMatrix = new std::vector<Event>** [gameData.mapHeight];
    for (int i = 0; i != gameData.mapHeight; i++) {
        eventMatrix[i] = new std::vector<Event>*;
        for (int j = 0; j != gameData.mapWidth; j++) {
        eventMatrix[i][j] = NULL;
        }
    }
    */

 /*    PulverizeEvents(currentEventList); 
    return true;
}
  */

EventsData::EventsData() : eventMatrix(gameData.mapWidth, gameData.mapHeight, true)
{
    EventFactory eFactory;
    str path = systemData.resourcesDirectory + systemData.nextLocationName + "/events";
    eFactory.InitAll(path, currentEventList); 
    
    
    PulverizeEvents(currentEventList);     
}

Event* EventsData::getEvent(const str key) {
    return &currentEventList.at(key);
}

Event* EventsData::getEvent(Coord point) {
    if (!surfaceData.CoordIsValid(point)) return NULL;
    if (!eventMatrix[point]) return NULL;
    auto ev = eventMatrix[point];
    if (!eventMatrix[point]->empty()) 
        return &eventMatrix[point]->front();
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

                if (!eventMatrix[eventCenter]) {
                    eventMatrix[eventCenter] = new std::vector<Event>;
                eventMatrix[eventCenter]->push_back(event);
                }
                else {
                    eventMatrix[eventCenter]->push_back(event);  

                    std::push_heap( // SIC! that wasn't tested
                        eventMatrix[eventCenter]->begin(),
                        eventMatrix[eventCenter]->end(),
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
    Coord startPos (center.x - radius, center.y - radius);

    for (; startPos.x < center.x + radius; startPos.x++) {
        for (; startPos.y < center.y + radius; startPos.y++) {
            if ( surfaceData.CoordIsValid( startPos ) ) {
                std::pop_heap(eventMatrix[startPos]->begin(), 
                eventMatrix[startPos]->end(),
                [](Event& a, Event& b) {
                    return a.getPriority() < b.getPriority();
                } );
            };
        }
    }
}

bool EventsData::EventExists(str ID) {
    return true;
    // currentEventList.count(ID);
}

//---------------------------------------------------------
//---------------- ArtifactsData --------------------------
//---------------------------------------------------------

/* bool ArtifactsData::Init() {
    ArtifactFactory aFactory;
    str path = systemData.resourcesDirectory + systemData.nextLocationName + "/artifacts";
    aFactory.InitAll(path, currentArtifactsList);
    return true;
} */

ArtifactsData::ArtifactsData() {
    ArtifactFactory aFactory;
    str path = systemData.resourcesDirectory + systemData.nextLocationName + "/artifacts";
    aFactory.InitAll(path, currentArtifactsList); 
}

Artifact* ArtifactsData::getArtifact(const str key) {
    return &currentArtifactsList.at(key);
}

bool ArtifactsData::ArtifactExists(str ID) {
    // currentArtifactsList.count(ID);
    // return my_map[k1].find(k2) != my_map[k1].end();
    return currentArtifactsList.find(ID) != currentArtifactsList.end();
    // return false;
}

//---------------------------------------------------------
//--------------------- GameData --------------------------
//---------------------------------------------------------



//---------------------------------------------------------
//--------------------- SystemData ------------------------
//---------------------------------------------------------

SystemData::SystemData(str _nextLocationName)
: 
resourcesDirectory("resources/"), 
nextLocationName(_nextLocationName), 
mapName("map") {

}