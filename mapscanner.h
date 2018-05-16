#ifndef MAP_SCANNER
#define MAP_SCANNER

#include <string>

using str = std::string;

struct MapData {
    int mapWidth;
    int mapHeight;
    short** surfaceMatrix;
};

class MapScanner { // scans the map
public:
    MapData& getMap(const str);
private:
    MapData data;
    bool InitMatrix(const str);
};

#endif  // MAP_SCANNER