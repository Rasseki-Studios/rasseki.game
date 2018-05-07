#include "item.h"

//---ITEM---
Item::Item(str _ID, str _name, short _level)
: ID(_ID), name(_name), level(_level) {}

str Item::getId() const {
    return ID;
}

str Item::getName() const {
    return name;
}

short Item::getLevel() const {
    return level;
}

ItemData::ItemData(str _ID, str _name, short _level) 
: ID(_ID), name(_name), level(_level) {};