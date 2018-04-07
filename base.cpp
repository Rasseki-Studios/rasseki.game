#include "base.h"

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

//---MOVEBLE---
Moveble::Moveble(int, int) : Located(){}

void Moveble::Move(coord destination) {
    cout << destination.x << " - " << destination.y << endl;
}
