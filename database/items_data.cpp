#include "session_data.h"
// #include "event_factory.h"
#include "mapscanner.h"
#include <algorithm>
#include <vector>

using namespace SessionData;
using std::vector;
using std::cout;

//---------------------------------------------------------
//----------------- EventsData ----------------------------
//---------------------------------------------------------

EventsData::EventsData() : eventMatrix(gameData.mapWidth, gameData.mapHeight, true)
{
    EventFactory eFactory;
    str path = systemData.resourcesDirectory + systemData.nextLocationName + "/events";
    eFactory.InitAll(path, currentEventList); 
    PulverizeEvents(currentEventList);     
}

EventsData::~EventsData() {
    Coord temp;
    int counter = 0;
    for (temp.y = 0; temp.y < eventMatrix.getHeight(); temp.y++) {
        for (temp.x = 0; temp.x < eventMatrix.getHeight(); temp.x++) {
            if (eventMatrix[temp]) {
                // cout << "deleting event at " << temp << endl;   
                counter++;
                delete eventMatrix[temp];
            }
        }
    }
    cout << counter << " events were deleted by destructor" << endl;
}

Event* EventsData::getEvent(const str key) {
    return &currentEventList.at(key);
}

Event* EventsData::getEvent(Coord point) {
    if (!surfaceData.CoordIsValid(point)) return NULL;
    if (!eventMatrix[point]) return NULL;
    if (!eventMatrix[point]->empty()) 
        // return eventMatrix[point]->front();
        return getEvent(eventMatrix[point]->front());
    else return NULL;
}

bool ComparePriorities(str lvalue, str rvalue) {
    Event* left = eventsData.getEvent(lvalue);
    Event* right = eventsData.getEvent(rvalue);
    return left->getPriority() < right->getPriority();
};

void EventsData::PulverizeEvents(std::unordered_map<str, Event>& list) {
/* 
parsing map - getting event and spraying it at the map. 
get event
add event to map
*/
    for (auto i : list) {
        Event &event = i.second;
        int counter = 0;

        Coord eventCenter = event.GetCoord();
        Coord current;

        for (current.x = eventCenter.x - event.getRadius();
        current.x <= eventCenter.x + event.getRadius();
        current.x++) {
            for (current.y = eventCenter.y - event.getRadius(); 
            current.y <= eventCenter.y + event.getRadius(); 
            current.y++) {
                // std::cout << "spraying event \"" << event.GetName() <<"\" at " 
                // << current.x << ", " << current.y  << endl;
                counter++;
                if (!eventMatrix[current]) {
                    eventMatrix[current] = new std::vector<str>;
                    eventMatrix[current]->push_back(event.GetId());
                } else {
                    eventMatrix[current]->push_back(event.GetId());  
                    std::push_heap(
                        eventMatrix[current]->begin(),
                        eventMatrix[current]->end(),
                        ComparePriorities
                    );
                }
            }
        }
        cout << "event " << event.GetName() << " was sprayed " << counter << " times" << endl;
    }
}

void EventsData::RemoveFrontEvent(Coord point) {
    Event* event = getEvent(point);
    if (!event) return;
    Coord center = event->GetCoord();
    int radius = event->getRadius();
    int counter = 0;
    Coord startPos;

    for (startPos.x = center.x - radius; startPos.x <= center.x + radius; startPos.x++) {
        for (startPos.y = center.y - radius; startPos.y <= center.y + radius; startPos.y++) {
            if ( surfaceData.CoordIsValid( startPos ) ) {
                std::pop_heap(eventMatrix[startPos]->begin(), 
                    eventMatrix[startPos]->end(),
                    ComparePriorities 
                );
                eventMatrix[startPos]->pop_back();
                counter++;
            };
        }
    }
    cout << counter<< " events were deleted" << endl;
}

bool EventsData::EventExists(str ID) {
    return currentEventList.count(ID);
}

//---------------------------------------------------------
//---------------- ArtifactsData --------------------------
//---------------------------------------------------------

ArtifactsData::ArtifactsData() {
    ArtifactFactory aFactory;
    str path = systemData.resourcesDirectory + systemData.nextLocationName + "/artifacts";
    aFactory.InitAll(path, currentArtifactsList); 
}

Artifact* ArtifactsData::getArtifact(const str key) {
    return &currentArtifactsList.at(key);
}

bool ArtifactsData::ArtifactExists(str ID) {
    return currentArtifactsList.count(ID);
    // return currentArtifactsList.find(ID) != currentArtifactsList.end();
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
    cout << "systemData initialized" << endl;
}
