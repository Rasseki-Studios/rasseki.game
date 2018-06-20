#ifndef MAP_SCANNER
#define MAP_SCANNER

#include <string>
#include "matrix.hpp"
#include "libs/EasyBMP/EasyBMP.h"


using str = std::string;

class MapScanner { // scans the map
public:
    MapScanner (const str);
    void FillMatrix(Matrix<char>&);
    int getColor(Coord);
private:
    BMP map;
};

#endif  // MAP_SCANNER