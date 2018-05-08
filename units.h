#ifndef UNITS_H
#define UNITS_H

#include <string>

#include "things.h"
#include "location.h"

class Hero : public Item, public Movable {
public:
    Hero(std::string, std::string, short, short, coord, Storage*);
    Storage* GetInventory() const;
protected:
    Storage *inventory;
};

class Creature : public Item, public Movable {
public:
    Creature(std::string, std::string, short, short, coord);
};

#endif //UNITS_H
