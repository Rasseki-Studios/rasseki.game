#ifndef UNITS_H
#define UNITS_H

#include <string>

#include "Things.h"
#include "Location.h"

class Creature : public Item, public Movable {
public:
    Creature(std::string, std::string, short, short, coord);
};

class Hero : public Creature {
public:
    Hero(std::string, std::string, short, short, coord, Storage*);
    Storage* GetInventory() const;
protected:
    Storage *inventory;
};

#endif //UNITS_H
