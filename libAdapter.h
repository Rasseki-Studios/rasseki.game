#ifndef LIBADAPTER_H
#define LIBADAPTER_H

#include <vector>
#include <string>

#include "movable.h"
#include "surface.h"

int Game();
void Exit();
void Moving(int);
bool Save(std::string);
void Load(std::string);
std::string Write(std::string *);
std::vector<std::string> GetSavedNames();
int Go(int x, int y);
coord Coords();
coord EndOfMap();
std::vector<str> Data();

#endif //LIBADAPTER_H
