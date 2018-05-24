#include "location.h"

//---coord---
coord::coord(int _x, int _y) :
    x(_x),
    y(_y) {
}

bool operator==(const coord& left, const coord& right) {
    return left.x == right.x && left.y == right.y;
}

//---LOCATED---
Located::Located(coord _coord) : 
    coordinates(_coord) {
}

void Located::SetCoord(coord coordinates) {
    this->coordinates = coordinates;
}

coord Located::GetCoord() const {
    return coordinates;
}