#ifndef HERO_H
#define HERO_H

#include <string>

#include "movable.h"
#include "storage.h"

class Hero : public Item, public Movable {
public:
    Hero(std::string, std::string, short, short, coord, Storage*);
    Storage* GetInventory();
protected:
    Storage inventory;
};

#endif //HERO_H
