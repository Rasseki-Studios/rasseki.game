#include "mapdata.h"

std::unordered_map<std::string, Event> EventData::eventsList;
std::vector<Event> ***EventData::eventMatrix = nullptr;

void EventData::initEventMatrix() {
    int height = SurfaceData::getHeight();
    int width = SurfaceData::getWidth();
    eventMatrix = new std::vector<Event> **[height];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            eventMatrix[i][j] = nullptr;
        }
    }
}

void EventData::addEvent(Event event) {
    eventsList.insert(make_pair(event.GetId(), event));

    int width = SurfaceData::getWidth();
    int height = SurfaceData::getHeight();
    
    coord eventCenter = event.GetCoord();
    if (eventCenter.x > width || eventCenter.y > height) throw "coordinates are out of range";
    if (eventCenter.x < 0 || eventCenter.y < 0) throw "invalid coordinates";
    
    for (int i = eventCenter.x - event.radius; i <= eventCenter.x + event.radius; i++) {
        for (int j = eventCenter.y - event.radius; j <= eventCenter.y + event.radius; j++) {
            
            if (eventCenter.y + event.radius > height || eventCenter.x + event.radius > height) break;
            if (!eventMatrix[eventCenter.x][eventCenter.y]) {
                eventMatrix[eventCenter.x][eventCenter.y] = new std::vector<Event>;
            }
            eventMatrix[eventCenter.x][eventCenter.y]->push_back(event);
            //here'll be sorting function
            
        }
    }
}

void EventData::printEvents() {
    //get an iterator pointing to begining of the map
/*     std::unordered_map<std::string, Event>::iterator it = eventsList.begin(); 

    while(it != eventsList.end()) {
        std::cout << it->first << " :: " << it->second.printEvData() << std::endl;
        it++;
    }  */
    // for (auto it : eventsList) it.second.printEvData();
}