#ifndef MAP_H
#define MAP_H
//This code uses free-distributed library "EasyBMP-1.06". 
//https://sourceforge.net/projects/easybmp/
//Great thanks to the authors of this pretty useful tool.

#include "EasyBMP/EasyBMP.h"
#include "base.h"

namespace Map {
    class MapData {
    public:
        MapData(const char*);
        ~MapData();
        short GetSurfaceType(coord*);
        void getContent(coord*); //here must be Event getContent(coord);
    private:
        int mapWidth;
        int mapHeight;
        short** surfaceMatrix;
        bool initSurfMatrix(const char*); //returns FALSE if something went wrong (e.g. file doesn't exist)
        // *vector<GUID> contentMap; 
        // map<GUID, Event> contentList;
        // map<GUID, SurfaceType> surfaceTypesList;
    };
}

#endif