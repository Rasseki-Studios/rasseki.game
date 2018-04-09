#include "base.h"
#include <iostream>

//---LOCATED---
Located::Located(int x, int y) {
    this->coordinates.x = x;
    this->coordinates.y = y;
}

coord Located::GetCoord() {
    return coordinates;
}

void Located::SetCoord(coord coordinates) {
    this->coordinates = coordinates;
}

// ---MOVABLE---
Movable::Movable(int x, int y) : Located(x, y){}

void Movable::Move(coord destination) {
    std::cout << destination.x << " - " << destination.y << std::endl;
}
