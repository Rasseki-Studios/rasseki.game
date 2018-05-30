#ifndef LIBADAPTER_H
#define LIBADAPTER_H

#include <vector>
#include <string>

#include "location.h"
#include "surface.h"

int Game();
void Moving(int);
std::string Write(std::string *);
int Go(int x, int y);
Coord Coords();
Coord EndOfMap();
std::vector<str> Data();

#endif //LIBADAPTER_H
