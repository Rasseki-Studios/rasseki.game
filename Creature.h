#ifndef CREATURE_H
#define CREATURE_H

#include "Item.h"
#include "Movable.h"

class Creature : public Item, public Movable {
public:
    Creature(std::string, std::string, short, short, coord);
};

#endif //CREATURE_H
