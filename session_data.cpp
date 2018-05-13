#include "session_data.h"
#include "mapdata.h"
#include <algorithm>

using std::vector;

bool SurfaceData::Init(const str locationName) {
    // open map, read it
    // asign map pointers
    // init factories

    MapScanner scanner;
    MapData data = scanner.getMap(locationName);
    surfaceMatrix = data.surfaceMatrix;
    mapHeight = data.mapHeight;
    mapWidth = data.mapWidth;
    GameData::setHeight(mapHeight);
    GameData::setWidth(mapWidth);
}

int SurfaceData::getWidth() {
    return mapWidth;
}

int SurfaceData::getWidth() {
    return mapHeight;
}

short SurfaceData::getSurface(coord point) {
    return surfaceMatrix[point.x][point.y];
}

bool EventsData::Init() {
    EventFactory eFactory;
    eFactory.InitAll("tests/events", currentEventList); //hardcoded just for debugging
    // std::unique_ptr<Event[][]> eventMatrix (nullptr);
    PulverizeEvents(currentEventList);
}

Event& EventsData::getEvent(const str key) {
    return currentEventList.at(key);
}

Event& EventsData::getEvent(coord point) {
    return eventMatrix[point.x][point.y]->front();
}

void EventsData::PulverizeEvents(std::unordered_map<str, Event>& list) {
/* 
parsing map - getting event and spraying it at the map. 
get event
add event to map
*/
    for (auto i : list) {
        Event event = i.second;
        
        int width = GameData::getWidth();
        int height = GameData::getHeight();

        coord eventCenter = event.GetCoord();
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
                    //here'll be sorting function
                    SortEventVector(eventMatrix[eventCenter.x][eventCenter.y]);
                }
            }
        }
    }
}
void EventsData::SortEventVector(std::vector<Event> * vector) {
    std::sort(vector->begin(), vector->end(), 
    [](Event& a, Event& b) -> bool {
        return a.getPriority() > b.getPriority();
    });
}

bool ArtifactsData::Init() {
    ArtifactFactory aFactory;
    aFactory.InitAll("tests/artifacts", currentArtifactsList);
}

Artifact& ArtifactsData::getArtifact(const str key) {
    return currentArtifactsList.at(key);
}

short GameData::getHeight() {
    return mapHeight;
}

short GameData::getWidth() {
    return mapWidth;
}

void GameData::setHeight(short _height) {
    mapHeight = _height;
}

void GameData::setWidth(short _width) {
    mapWidth = _width;
}