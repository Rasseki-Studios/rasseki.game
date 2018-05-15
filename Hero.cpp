#include "Hero.h"

Hero::Hero(std::string name, std::string id, short level, short speed, coord coordinates, Storage *inventory) : Creature(name, id, level, speed, coordinates), inventory(inventory) {}

Storage* Hero::GetInventory() const {
    return inventory;
}