#ifndef HERO_H
#define HERO_H

#include <string>

#include "event.h"
#include "movable.h"
#include "storage.h"

class Hero : public Item, public Movable {
public:
    Hero(std::string, std::string, short, short, coord, Storage*);
    Storage* GetInventory() const;
protected:
    Storage inventory;
};

#endif //HERO_H
