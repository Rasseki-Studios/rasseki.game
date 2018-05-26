#include "surface.h"
#include "mapscanner.h"
#include "session_data.h"

using namespace SessionData;

//---------------------------------------------------------
//---------------- SurfaceData ----------------------------
//---------------------------------------------------------

SurfaceData::SurfaceData()
: mapHeight(1000), mapWidth(1000), surfaceMatrix(mapWidth, mapHeight, false) {
    MapScanner scanner;
    scanner.FillMatrix(
        systemData.resourcesDirectory +
        systemData.nextLocationName + "/" +
        systemData.mapName + ".bmp",
        surfaceMatrix
    );
}

int SurfaceData::getWidth() {
    return mapWidth;
}

int SurfaceData::getHeight() {
    return mapHeight;
}

short SurfaceData::getSurface(Coord point) {
    if ((point.x < 0 || point.x > mapWidth) || (point.y < 0 || point.y > mapHeight))
        return -1;
    return surfaceMatrix.getValue(point);
}

bool SurfaceData::CoordIsValid(Coord point) {
    if ((point.x < 0 || point.x > mapWidth) || (point.y < 0 || point.y > mapHeight))
        return false;
    return true;
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

// DO NOT use this! It's full of bugs
AccessMap::AccessMap(Coord start, Coord end) {
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
                if (surfaceData.getSurface( (Coord){i, j} ) != 0) matrix[n][k] = 1;
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
