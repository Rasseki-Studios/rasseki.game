#ifndef MAP_H
#define MAP_H
/*
GUID needs to be explored
initSurfMatrix went to private section
*/

#include "base.h"

static class mapData {
public:
    int mapWidth;
    int mapHeight;
    short GetSurface(coord);
private:
    short** surfaceMap;
    bool initSurfMatrix(); //returns FALSE if something went wrong (e.g. file doesn't exist)
    // *vector<GUID> contentMap; 
    // map<GUID, Event> contentList;
    // map<GUID, SurfaceType> surfaceTypesList;

};
#endif