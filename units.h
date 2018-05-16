#ifndef UNITS_H
#define UNITS_H

#include <string>

#include "artifact.h"
#include "event.h"
#include "movable.h"

class Hero : public Item, public Movable {
public:
    Hero(str, str, short, short, coord, Storage*);
    Storage* GetInventory() const;
protected:
    Storage *inventory;
};

// TEMPORARY
/* class Creature : public Event, public Movable {
public:
    Creature(str, str, short, short, coord);
}; */

#endif //UNITS_H
