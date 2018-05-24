#include "surface.h"
#include "mapscanner.h"
#include "session_data.h"
#define ACCESSIBLE 1
#define NONACCESSIBLE 0

using namespace SessionData;

//---------------------------------------------------------
//---------------- SurfaceData ----------------------------
//---------------------------------------------------------

bool SurfaceData::Init() {
    // open map, read it
    // asign map pointers
    // init factories
    MapScanner scanner;
    MapData data = scanner.getMap(
        systemData.resourcesDirectory +
        systemData.nextLocationName + "/" +
        systemData.mapName + ".bmp");
    surfaceMatrix = data.surfaceMatrix;
    mapHeight = data.mapHeight;
    mapWidth = data.mapWidth;
    return true;
}

int SurfaceData::getWidth() {
    return mapWidth;
}

int SurfaceData::getHeight() {
    return mapHeight;
}

short SurfaceData::getSurface(coord point) {
    if ((point.x < 0 || point.x > mapWidth) || (point.y < 0 || point.y > mapHeight))
        return -1;
    return surfaceMatrix[point.x][point.y];
}

bool SurfaceData::CoordIsValid(coord point) {
    if ((point.x < 0 || point.x > mapWidth) || (point.y < 0 || point.y > mapHeight))
        return false;
    return true;
}

bool SurfaceData::RadiusIsValid(coord point, short radius) {
    if (
        (point.x - radius <= 0) || 
        (point.x + radius >= mapWidth) || 
        (point.y + radius >= mapHeight) ||
        (point.y - radius <= 0) ||
        (!CoordIsValid(point))
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

bool SurfaceData::IsWalkable(coord point) {
    if (getSurface(point)) return true;
    return false;
}

const short** SurfaceData::getMap() {
    return const_cast<const short**>(surfaceMatrix);
}

// DO NOT use this! It's full of bugs
AccessMap::AccessMap(coord start, coord end) {
    // start.x--; end.y++;
    width = abs(start.y - end.y);
    height = abs(start.x - end.x);

    int frame = 2; // hardcoded for a while
    int k = 0, n = 0;
    matrix = new char* [height];
    
    for (int i = 0; i < height; i++) { 
        matrix[i] = new char [width];
    }

    for (int i = start.x; i < end.x; i++) {
        for (int j = start.y; j < end.y; j++) {
            if (surfaceData.CoordIsValid( {i, j} )) {
                if (surfaceData.getSurface( (coord){i, j} ) != 0) matrix[n][k] = 1;
            else matrix[k][n] = 0;                
            }
            else matrix[k][n] = 0;
            n++;
        }
        n = 0;
        k++;
    }
}

AccessMap::~AccessMap() {
    for (int i = 0; i < height; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
}
