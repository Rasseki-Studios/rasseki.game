#include "Located.h"

coord::coord(int x, int y) : x(x), y(y) {}

Located::Located(coord coordinates) : coordinates(coordinates) {}

void Located::SetCoord(coord coordinates) {
    this->coordinates = coordinates;
}

coord Located::GetCoord() const {
    return coordinates;
}