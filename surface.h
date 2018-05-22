#ifndef SURFACE
#define SURFACE

#include "item.h"
#include "location.h"


/* 
// struct for terrain modifiers, contains name and power factor
struct surfaceModifier {
    str modifier;
    short modFactor;
}; 
*/

class Surface : public Item {
public:
    // surfaceModifier getModifier();
private:
    str modfier;
    short modFactor;
};


class SurfaceData {
public:
    bool Init();
    int getWidth();
    int getHeight();
    bool RadiusIsValid(coord, short);
    bool IsWalkable(coord);
    bool CoordIsValid(coord);
    short getSurface(coord);
    Surface& getSurface(str);
private:
    int mapWidth;
    int mapHeight;
    short** surfaceMatrix;    
    // std::unordered_map<str, Surface> currentSurfaceList; // currently useless
    // std::unordered_map<str, Surface> globalSurfaceList; //will be added in future
};

class AccessMap {
public:
    AccessMap(coord, coord);
    ~AccessMap();
    char** getMatrix() {return matrix;};
    int getHeight() {return height;};
    int getWidth() {return width;};
private:
    char** matrix;
    int height;
    int width;
};

/* template<class T>
class Matrix {
public:
    Matrix();
    Matrix(T**);
    ~Matrix();


private:
    T **matrixPointer;
    int width;
    int height;
}; */

#endif 