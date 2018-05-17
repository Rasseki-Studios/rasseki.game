#ifndef UNITS_H
#define UNITS_H

#include <string>

#include "event.h"
#include "movable.h"
#include "storage.h"

class Hero : public Item, public Movable {
public:
    Hero(str, str, short, short, coord);
    void giveArtifact(str ID);
    void takeArtifact(str ID);
private:
    Storage inventory;
};

// TEMPORARY
/* class Creature : public Event, public Movable {
public:
    Creature(str, str, short, short, coord);
}; */

#endif //UNITS_H
