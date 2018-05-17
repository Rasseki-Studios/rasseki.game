#include "units.h"

Hero::Hero (
    str name, str id, short level,
    short speed, coord coordinates
)
: Item(name, id, level), Movable(coordinates, speed) {}

void Hero::giveArtifact(str ID) {
    inventory.AddArtifact(ID);
}