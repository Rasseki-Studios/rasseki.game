#ifndef MAPDATA
#define MAPDATA

#include "location.h"
#include "event.h"
#include <unordered_map>
// #include <bits/stdc++.h>

#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif

class Event;

class SurfaceData {
public:
    static bool initMatrix(const std::string); //returns FALSE if something went wrong (e.g. file doesn't exist)
    static short getSurface(coord);
    static int getHeight();
    static int getWidth();
    static void setSurfMatrix(short**);
     ~SurfaceData();
private:
    static int mapWidth;
    static int mapHeight;
    static short** surfaceMatrix;
    // map<ID, SurfaceType> surfaceTypesList;
};


class EventsMapData {
public:
    static void initEventMatrix();
    static Event getContent(coord);
    static void addEvent(Event);
    static void printEvents(); //DEBUG FUNCTION

private:
    static std::unordered_map<std::string, Event> eventsList;
    static std::vector<Event> ***eventMatrix;
    static void sortEventVector(std::vector<Event>*);
};

#endif  // MAPDATA