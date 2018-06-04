#include "item.h"

Item::Item(str id, str name, short level) : id(id), name(name), level(level) {}

std::string Item::GetId() const {
    return id;
}

std::string Item::GetName() const {
    return name;
}

short Item::GetLevel() const {
    return level;
}

