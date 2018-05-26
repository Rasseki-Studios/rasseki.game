#include "location.h"

//---Coord---
Coord::Coord(int _x, int _y) :
    x(_x),
    y(_y) {
}

bool operator==(const Coord& left, const Coord& right) {
    return left.x == right.x && left.y == right.y;
}

//---LOCATED---
Located::Located(Coord _coord) : 
    coordinates(_coord) {
}

void Located::SetCoord(Coord coordinates) {
    this->coordinates = coordinates;
}

Coord Located::GetCoord() const {
    return coordinates;
}