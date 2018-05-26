#include "hero.h"

Hero::Hero(str id, str name, short level, short speed, Coord coordinates) 
: Item(id, name, level), Movable(coordinates, speed) {}

Storage* Hero::GetInventory() {
    return &inventory;
}