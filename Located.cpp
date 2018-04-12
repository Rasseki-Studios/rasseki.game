#include "Located.h"

Located::Located(coord coordinates) {
    this->coordinates = coordinates;
}

void Located::SetCoord(coord coordinates) {
    this->coordinates = coordinates;
}

coord Located::GetCoord() const {
    return coordinates;
}