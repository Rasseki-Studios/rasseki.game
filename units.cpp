#include "units.h"

Hero::Hero (
    str name, str id, short level, 
    short speed, coord coordinates, 
    Storage *inventory
)
: Item(name, id, level), Movable(coordinates, speed), inventory(inventory) {}

Storage* Hero::GetInventory() const {
    return inventory;
}