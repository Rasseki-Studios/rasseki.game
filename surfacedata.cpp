#include "mapdata.h"

// int SurfaceMap::mapWidth = 0;
// int SurfaceMap::mapHeight = 0;
// short** SurfaceMap::surfaceMatrix = nullptr;

SurfaceMap::~SurfaceMap() {
    for (int i = 0; i < mapHeight; i++) {
        if (surfaceMatrix[i]) delete [] surfaceMatrix[i];
    }
    delete [] surfaceMatrix;
}

short SurfaceMap::getSurface(coord point) {
    return surfaceMatrix[point.x][point.y];
}


int SurfaceMap::getWidth() {
    return mapWidth;
} 

int SurfaceMap::getHeight() {
    return mapHeight;
}

void SurfaceMap::setSurfMatrix(const str filename) {
    // MapScanner scanner;
    X mapData = MapScanner::getMap();
    surfaceMatrix = X.surfaceMatrix;

}

bool CurrentLocData::Init(const str filename) {
    X mapData = MapScanner::getMap();
    surfaceMatrix = X.surfaceMatrix;
    mapWidth = X.mapWidth;
    mapHeight = X.mapHeight;
}