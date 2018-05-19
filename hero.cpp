#include "hero.h"

Hero::Hero(std::string id, std::string name, short level, short speed, coord coordinates, Storage *inventory) : Creature(name, id, level, speed, coordinates), inventory(inventory) {}

Storage* Hero::GetInventory() const {
    return inventory;
}