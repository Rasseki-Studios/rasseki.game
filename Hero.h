#ifndef HERO_H
#define HERO_H

#include <string>

#include "Creature.h"
#include "Storage.h"

class Hero : public Creature {
public:
    Hero(std::string, std::string, short, short, coord, Storage*);
    Storage* GetInventory() const;
protected:
    Storage *inventory;
};

#endif //HERO_H
