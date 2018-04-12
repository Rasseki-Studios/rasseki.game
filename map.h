#ifndef MAP_H
#define MAP_H
//This code uses free-distributed library "EasyBMP-1.06". 
//https://sourceforge.net/projects/easybmp/
//Great thanks to the authors of this pretty useful tool.

#include "EasyBMP/EasyBMP.h"
#include "base.h"

class MapData {
public:
    ~MapData();
    static bool initSurfMatrix(const str); //returns FALSE if something went wrong (e.g. file doesn't exist)
    static short GetSurfaceType(coord*);
    inline static void getContent(coord*); //here must be Event getContent(coord);
    inline static int getHeight();
    inline static int getWidth();
private:
    static int mapWidth;
    static int mapHeight;
    static short** surfaceMatrix;
    // *vector<GUID> contentMap; 
    // map<GUID, Event> contentList;
    // map<GUID, SurfaceType> surfaceTypesList;
};

#endif