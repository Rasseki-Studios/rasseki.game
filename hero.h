#ifndef HERO_H
#define HERO_H

#include <string>

//#include "event.h"
#include "movable.h"
#include "storage.h"

class Hero : public Item, public Movable {
public:
    Hero(str, str, short, short, coord);
    Storage* GetInventory();
protected:
    Storage inventory;
};

#endif //HERO_H
