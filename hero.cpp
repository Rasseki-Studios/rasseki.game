#include "hero.h"

const unsigned int storage_size = 5;

Hero::Hero(str id, str name, short level, short speed, coord coordinates) : Item(id, name, level), Movable(coordinates, speed) {
    //inventory = Storage(storage_size);
}

Storage* Hero::GetInventory() {
    return &inventory;
}