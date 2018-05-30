#include "location.h"

//---Coord---
Coord::Coord(int x, int y) : x(x), y(y) {}

bool operator==(const Coord& left, const Coord& right) {
    return left.x == right.x && left.y == right.y;
}

//---Located---
Located::Located(Coord coordinates) : coordinates(coordinates) {}

void Located::SetCoord(Coord coordinates) {
    this->coordinates = coordinates;
}

Coord Located::GetCoord() const {
    return coordinates;
}