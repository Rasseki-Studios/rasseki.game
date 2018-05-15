#include "Creature.h"

Creature::Creature(std::string name, std::string id, short level, short speed, coord coordinates) : Item(name, id, level), Movable(coordinates, speed) {}
