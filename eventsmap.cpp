#include "mapdata.h"
#include <algorithm>

// std::unordered_map<std::string, Event> EventsMap::eventsList;
// std::vector<Event> ***EventsMap::eventMatrix = nullptr;

bool EventsMap::InitMatrix() {
    int height = SurfaceMap::getHeight();
    int width = SurfaceMap::getWidth();
    eventMatrix = new std::vector<Event> **[height];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            eventMatrix[i][j] = nullptr;
        }
    }
    return true;
}

EventsMap::~EventsMap() {

}

void EventsMap::AddEvent(Event event) {
    eventsList.insert(make_pair(event.GetId(), event));

    int width = SurfaceMap::getWidth();
    int height = SurfaceMap::getHeight();
    
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

            if (!SurfaceMap::getSurface(eventCenter)) break;

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

void EventsMap::PrintEvents() {
    //get an iterator pointing to begining of the map
     std::unordered_map<std::string, Event>::iterator it = eventsList.begin(); 
     for (auto it : eventsList) it.second.printEvent();
}

void EventsMap::SortEventVector(std::vector<Event> * vector) {
    std::sort(vector->begin(), vector->end(), 
    [](Event& a, Event& b) -> bool {
        return a.getPriority() > b.getPriority();
    });
}

Event& EventsMap::getEvent(coord& point) {
    return eventMatrix[point.x][point.y]->at(0);
}