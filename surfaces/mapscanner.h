#ifndef MAP_SCANNER
#define MAP_SCANNER

#include <string>
#include "matrix.hpp"


using str = std::string;

class MapScanner { // scans the map
public:
    MapScanner () {};
    void FillMatrix(const str, Matrix<char>&);
};

#endif  // MAP_SCANNER