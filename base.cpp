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

inline coord Located::GetCoord() const {return coordinates;}


//---MOVABLE---
Movable::Movable(coord coordinates, short speed) : Located(coordinates) {
    this->speed = speed;
}

/* bool Movable::Move(coord destination) {
    //движение
} */

inline short Movable::GetSpeed() const {return speed;}


//---ITEM---
Item::Item(str ID, str name, short level) {
    this->ID = ID;
    this->name = name;
    this->level = level;
}

inline str Item::GetId() const {return ID;}

inline str Item::GetName() const {return name;}

inline short Item::GetLevel() const {return level;}