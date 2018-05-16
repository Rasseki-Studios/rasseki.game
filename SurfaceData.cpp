#include "SurfaceData.h"

SurfaceData::SurfaceData(int mapW, int mapH) : mapWidth(mapW), mapHeight(mapH) {};
int SurfaceData::getWidth() {return mapWidth;}
int SurfaceData::getHeight() {return mapHeight;}
bool SurfaceData::IsWalkable(coord& point) {return true;}