#include "item.h"

Item::Item(std::string id, std::string name, short level) : id(id), name(name), level(level) {}

std::string Item::getId() const {
    return id;
}

std::string Item::getName() const {
    return name;
}

short Item::getLevel() const {
    return level;
}
