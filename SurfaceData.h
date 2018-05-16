#ifndef SURFACEDATA_H
#define SURFACEDATA_H

#include "Located.h"

class SurfaceData {
public:
    SurfaceData(int, int);
    int getWidth();
    int getHeight();
    bool IsWalkable(coord& point);
private:
    int mapWidth;
    int mapHeight;
};

#endif //SURFACEDATA_H