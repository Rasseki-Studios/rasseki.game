#include "mapdata.h"
#include <algorithm>

std::unordered_map<std::string, Event> EventsMapData::eventsList;
std::vector<Event> ***EventsMapData::eventMatrix = nullptr;

void EventsMapData::initEventMatrix() {
    int height = SurfaceData::getHeight();
    int width = SurfaceData::getWidth();
    eventMatrix = new std::vector<Event> **[height];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            eventMatrix[i][j] = nullptr;
        }
    }
}

void EventsMapData::addEvent(Event event) {
    eventsList.insert(make_pair(event.GetId(), event));

    int width = SurfaceData::getWidth();
    int height = SurfaceData::getHeight();
    
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

            if (!eventMatrix[eventCenter.x][eventCenter.y]) {
                eventMatrix[eventCenter.x][eventCenter.y] = new std::vector<Event>;
            eventMatrix[eventCenter.x][eventCenter.y]->push_back(event);
            }
            else {
                eventMatrix[eventCenter.x][eventCenter.y]->push_back(event);            
                //here'll be sorting function
                sortEventVector(eventMatrix[eventCenter.x][eventCenter.y]);
            }
        }
    }
}

void EventsMapData::printEvents() {
    //get an iterator pointing to begining of the map
     std::unordered_map<std::string, Event>::iterator it = eventsList.begin(); 
/*
    while(it != eventsList.end()) {
        std::cout << it->first << " :: " << it->second.printEvent() << std::endl;
        it++;
    }  */
     for (auto it : eventsList) it.second.printEvent();
}

void EventsMapData::sortEventVector(std::vector<Event> * vector) {
    std::sort(vector->begin(), vector->end(), 
    [](Event& a, Event& b) -> bool {
        return a.getPriority() > b.getPriority();
    });
}