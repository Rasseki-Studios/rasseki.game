#include "item.h"

//---ITEM---
Item::Item(str _ID, str _name, short _level)
: ID(_ID), name(_name), level(_level) {}

str Item::GetId() const {
    return ID;
}

str Item::GetName() const {
    return name;
}

short Item::GetLevel() const {
    return level;
}
