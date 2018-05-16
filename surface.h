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
    bool RadiusIsValid(coord&, short);
    bool IsWalkable(coord&);
    short getSurface(coord&);
    Surface& getSurface(str);   
private:
    bool CoordIsValid(coord&);
    int mapWidth, mapHeight;
    short** surfaceMatrix;    
    // std::unordered_map<str, Surface> currentSurfaceList; // currently useless
    // std::unordered_map<str, Surface> globalSurfaceList; //will be added in future
};

#endif 