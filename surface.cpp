#include "surface.h"
#include "mapscanner.h"
#include "session_data.h"

//---------------------------------------------------------
//---------------- SurfaceData ----------------------------
//---------------------------------------------------------

bool SurfaceData::Init(const str locationName) {
    // open map, read it
    // asign map pointers
    // init factories

    MapScanner scanner;
    MapData data = scanner.getMap(locationName);
    surfaceMatrix = data.surfaceMatrix;
    mapHeight = data.mapHeight;
    mapWidth = data.mapWidth;
    GameData::mapHeight = mapHeight;
    GameData::mapWidth = mapWidth;
    return true;
}

int SurfaceData::getWidth() {
    return mapWidth;
}

int SurfaceData::getHeight() {
    return mapHeight;
}

short SurfaceData::getSurface(coord& point) {
    if ((point.x <= 0 || point.x >= mapWidth) || (point.y <= 0 || point.y >= mapHeight))
        return -1;
    return surfaceMatrix[point.x][point.y];
}

bool SurfaceData::isValidCoord(coord& point) {
    if ((point.x < 0 || point.x > mapWidth) || (point.y < 0 || point.y > mapHeight))
        return false;
    return true;
}

bool SurfaceData::isValidRadius(coord& point, short radius) {
    if (
        (point.x - radius <= 0) || 
        (point.x + radius >= mapWidth) || 
        (point.y + radius >= mapHeight) ||
        (point.y - radius <= 0) ||
        (!isValidCoord(point))
    ) return false;

    bool flag = false;
    coord temp;
    for (int i = point.x - radius; i < point.x + radius; i++) {
        for (int j = point.y - radius; j < point.y + radius; j++) {
            temp.x = i; temp.y = j;
            if (getSurface(temp)) flag = true;
        }
    }
    
    return flag;
}
