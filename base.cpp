#include "base.h"

//---LOCATED---
Located::Located(int x, int y) {
    this->coordinates.x = x;
    this->coordinates.y = y;
}

void Located::SetCoord(coord coordinates) {
    this->coordinates = coordinates;
}

inline coord Located::GetCoord() const {return coordinates;}


//---MOVABLE---
Movable::Movable(coord coordinates, short speed) : Located(coordinates.x, coordinates.y) {
    this->speed = speed;
}

bool Movable::Move(coord destination) {
    //движение
}

inline short Movable::GetSpeed() const {return speed;}


//---ITEM---
Item::Item(std::string name, short level) {
    this->name = name;
    this->level = level;
}

inline short Item::GetId() const {return id;}

inline std::string Item::GetName() const {return name;}

inline short Item::GetLevel() const {return level;}