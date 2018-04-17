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

class Event;

class MapData {
public:
    static bool initMatrix(const std::string); //returns FALSE if something went wrong (e.g. file doesn't exist)
    static short getSurface(coord);
    static Event getContent(coord); //here must be Event getContent(coord);
    static int getHeight();
    static int getWidth();
    static void setSurfMatrix(short**);
    static void addEvent(Event);
    ~MapData();
private:
    static int mapWidth;
    static int mapHeight;
    static short** surfaceMatrix;
    static std::unordered_map<std::string, Event> eventsList;
    // map<ID, SurfaceType> surfaceTypesList;
};

#endif  // MAPDATA
  