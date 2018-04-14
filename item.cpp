#include "item.h"

//---ITEM---
Item::Item(str ID, str name, short level) {
    this->ID = ID;
    this->name = name;
    this->level = level;
}

str Item::GetId() const {
    return ID;
}

str Item::GetName() const {
    return name;
}

short Item::GetLevel() const {
    return level;
}
