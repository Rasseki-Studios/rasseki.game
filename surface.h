#include "item.h"

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
    bool Init(const str);
    int getWidth();
    int getHeight();
    bool **GetMiniMap(); // coming soon
    short getSurface(coord&);
    Surface& getSurface(str);   
    bool isValidRadius(coord&, short);
    bool isValidCoord(coord&);
private:
    int mapWidth, mapHeight;
    short** surfaceMatrix;
    // std::unordered_map<str, Surface> currentSurfaceList; // currently useless
    // std::unordered_map<str, Surface> globalSurfaceList; //will be added in future

};