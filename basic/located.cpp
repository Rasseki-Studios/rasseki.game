#include "located.h"

//---LOCATED---
Located::Located(Coord _coord)
: coordinates(_coord) {}

void Located::SetCoord(Coord coordinates) {
    this->coordinates = coordinates;
}

Coord Located::GetCoord() const {
    return coordinates;
}