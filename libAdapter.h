#ifndef LIBADAPTER_H
#define LIBADAPTER_H

#include <vector>
#include <string>

#include "movable.h"

int Game();
void Exit();
void Moving(int);
bool Save(std::string);
void Load(std::string);
std::string Write();
std::vector<std::string> GetSavedNames();
int Go(int x, int y);
coord Coords();
std::string Name();

#endif //LIBADAPTER_H
