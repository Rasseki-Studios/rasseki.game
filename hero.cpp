#include "hero.h"

Hero::Hero(std::string id, std::string name, short level, short speed, Coord coordinates) : Item(id, name, level), Movable(coordinates, speed) {}

Storage* Hero::GetInventory() {
    return &inventory;
}