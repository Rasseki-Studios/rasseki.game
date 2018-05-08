#ifndef MAPDATA
#define MAPDATA

#include <unordered_map>
#include <string>
#include <vector>

#include "location.h"
#include "event.h"

class Event;

class SurfaceMap {
public:
    // returns FALSE if something went wrong (e.g. file doesn't exist)
    // bool InitMatrix(const stССd::string); в отдельный класс
    SurfaceMap();
    short getSurface(coord);
    void setSurfMatrix(short**);  
    // int getHeight(); в специфик бля
    // int getWidth(); в специфик бля
    ~SurfaceMap();
private:
    // int mapWidth; в специфик бля
    // int mapHeight; в специфик бля
    short** surfaceMatrix;
    // map<ID, SurfaceType> surfaceTypesList;
};


class EventsMap {
public:
    EventsMap();
    // bool InitMatrix(); в конструктор бля
    void AddEvent(Event);
    /* DEBUG FUNCTION */ void PrintEvents();
    Event& getEvent(coord&);
    ~EventsMap();
private:
    std::unordered_map<std::string, Event> eventsList;
    std::vector<Event> ***eventMatrix;
    void SortEventVector(std::vector<Event>*);
};

#endif  // MAPDATA