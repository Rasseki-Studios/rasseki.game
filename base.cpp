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
Movable::Movable(coord coordinates, short speed) : Located(coordinates.x, coordinates.y) {
    this->speed = speed;
}

void Movable::Move(coord destination) {
    //движение
}

short Movable::GetSpeed() {
    return speed;
}


//---ITEM---
Item::Item(std::string name, short level) {
    this->name = name;
    this->level = level;
}

short Item::GetId() {
    return id;
}

std::string Item::GetName() {
    return name;
}

short Item::GetLevel() {
    return level;
}