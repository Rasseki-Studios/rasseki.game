#include "base.h"


//---coord---
coord::coord(int _x, int _y) : 
    x(_x),
    y(_y) {
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

//---ITEM---
Item::Item(str ID, str name, short level) {
    this->ID = ID;
    this->name = name;
    this->level = level;
}

str Item::GetId() const {
    return ID;
}

str Item::GetName() const {
    return name;
}

short Item::GetLevel() const {
    return level;
}
