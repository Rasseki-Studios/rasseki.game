#include "surface.h"
#include "mapscanner.h"
#include "session_data.h"

using namespace SessionData;

//---------------------------------------------------------
//---------------- SurfaceData ----------------------------
//---------------------------------------------------------

SurfaceData::SurfaceData()
:
mapWidth(1000), mapHeight(1000), surfaceMatrix(mapWidth, mapHeight, false) {
    MapScanner scanner;
    scanner.FillMatrix(
        systemData.resourcesDirectory +
        systemData.nextLocationName + "/" +
        systemData.mapName + ".bmp",
        surfaceMatrix
    );
    gameData.mapWidth = mapWidth;
    gameData.mapHeight = mapHeight;
}

int SurfaceData::getWidth() {
    return mapWidth;
}

int SurfaceData::getHeight() {
    return mapHeight;
}

short SurfaceData::getSurface(Coord point) {
    return surfaceMatrix[point];
}

bool SurfaceData::CoordIsValid(Coord point) {
    return surfaceMatrix.CoordIsValid(point);
}

bool SurfaceData::RadiusIsValid(Coord point, short radius) {
    if (
        (point.x - radius <= 0) || 
        (point.x + radius >= mapWidth) || 
        (point.y + radius >= mapHeight) ||
        (point.y - radius <= 0) ||
        (!CoordIsValid(point))
    ) return false;

    bool flag = false;
    Coord temp;
    for (int i = point.x - radius; i < point.x + radius; i++) {
        for (int j = point.y - radius; j < point.y + radius; j++) {
            temp.x = i; temp.y = j;
            if (getSurface(temp)) flag = true;
        }
    }
    
    return flag;
}

bool SurfaceData::IsWalkable(Coord point) {
    if (getSurface(point)) return true;
    return false;
}

const Matrix<char>& SurfaceData::getMap() {
    return surfaceMatrix;
}