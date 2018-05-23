#include "item.h"

Item::Item(str id, str name, short level) : id(id), name(name), level(level) {}

str Item::GetId() const {
    return id;
}

str Item::GetName() const {
    return name;
}

short Item::GetLevel() const {
    return level;
}

