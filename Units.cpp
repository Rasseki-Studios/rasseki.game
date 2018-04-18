#include "Units.h"

//---CREATURE---
Creature::Creature(std::string name, std::string id, short level, short speed, coord coordinates) : Item(name, id, level), Movable(coordinates, speed) {}


//---HERO---
Hero::Hero(std::string name, std::string id, short level, short speed, coord coordinates, Storage *inventory) : Creature(name, id, level, speed, coordinates) {
    this->inventory = inventory;
}

Storage* Hero::GetInventory() const {
    return inventory;
}