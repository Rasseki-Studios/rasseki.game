#ifndef MAP_SCANNER
#define MAP_SCANNER

#include <string>

using str = std::string;

struct X { // temp name
    int mapWidth;
    int mapHeight;
    short** surfaceMatrix;
};

class MapScanner { // scans the map
public:
    X& getMap(const str);
private:
    X data;
    bool InitMatrix(const str);
};

#endif  // MAP_SCANNER