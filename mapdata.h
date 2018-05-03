#ifndef MAPDATA
#define MAPDATA

#include "location.h"
#include "event.h"
#include <unordered_map>
#include <string>
#include <vector>

class Event;

class SurfaceMapData {
public:
    //returns FALSE if something went wrong (e.g. file doesn't exist)
    static bool initMatrix(const std::string); 
    static short getSurface(coord);
    static int getHeight();
    static int getWidth();
    static void setSurfMatrix(short**);
    ~SurfaceMapData();
private:
    static int mapWidth;
    static int mapHeight;
    static short** surfaceMatrix;
    // map<ID, SurfaceType> surfaceTypesList;
};


class EventsMapData {
public:
    static bool initMatrix();
    static void addEvent(Event);
    static void printEvents(); //DEBUG FUNCTION
    static Event& getEvent(coord&);
    ~EventsMapData();
private:
    static std::unordered_map<std::string, Event> eventsList;
    static std::vector<Event> ***eventMatrix;
    static void sortEventVector(std::vector<Event>*);
};

#endif  // MAPDATA