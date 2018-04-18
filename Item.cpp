#include "Item.h"

Item::Item(std::string id, std::string name, short level) : id(id), name(name), level(level) {}

std::string Item::GetId() const {
    return id;
}

std::string Item::GetName() const {
    return name;
}

short Item::GetLevel() const {
    return level;
}