#include "surface.h"
#include "mapscanner.h"
#include "session_data.h"
#include "config.h"

using namespace SessionData;

//---------------------------------------------------------
//---------------- SurfaceData ----------------------------
//---------------------------------------------------------

SurfaceData::SurfaceData()
:
mapWidth(definedMapHeight), mapHeight(definedMapHeight), surfaceMatrix(mapWidth, mapHeight, false) {
    MapScanner scanner;
    scanner.FillMatrix(
        systemData.resourcesDirectory +
        systemData.nextLocationName + "/" +
        systemData.mapName + ".bmp",
        surfaceMatrix
    );
    gameData.mapWidth = mapWidth;
    gameData.mapHeight = mapHeight;

    // temporarily hardcoded, will be removed in the future
    Surface Pathless((str)"Pathless", (str)"Pathless", 0, 1);
    Surface Mountain((str)"Mountain", (str)"Mountain", 0, 10);    
    Surface Field((str)"Field", (str)"Field", 0, 50);
    Surface Road((str)"Road", (str)"Road", 0, 100);

    surfaceList.push_back(Pathless);
    surfaceList.push_back(Mountain);    
    surfaceList.push_back(Field);
    surfaceList.push_back(Road);
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

short SurfaceData::getSurfSpeed(Coord point) {
    return surfaceList.at(getSurface(point)).getSpeed();
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
    return getSurface(point);
}

const Matrix<char>& SurfaceData::getMap() {
    return surfaceMatrix;
}

Surface::Surface(str _ID, str _name, int _level, int _speed) 
: Item(_ID, _name, _level), speed(_speed) { } ;
 
short Surface::getSpeed() {
    return speed;
}