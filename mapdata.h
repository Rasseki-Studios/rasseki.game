#ifndef MAPDATA
#define MAPDATA

#include "location.h"

#ifndef STRING
#define STRING
#include <string>
#endif

class MapData {
public:
    static bool initSurfMatrix(const std::string); //returns FALSE if something went wrong (e.g. file doesn't exist)
    static short getSurfaceType(coord);
    static void getContent(coord); //here must be Event getContent(coord);
    static int getHeight();
    static int getWidth();
    ~MapData();
private:
    static int mapWidth;
    static int mapHeight;
    static short** surfaceMatrix;
    // *vector<ID> contentMap; 
    // map<ID, Event> contentList;
    // map<ID, SurfaceType> surfaceTypesList;
};

#endif  // MAPDATA