#ifndef LIBADAPTER_H
#define LIBADAPTER_H

#include <vector>
#include <string>
#include <thread>

#include "Movable.h"


int Game();
void Exit();
void Moving(int);
bool Save(std::string);
void Load(std::string);
std::vector<std::string> GetSavedNames();
int Go(int x, int y);
coord Coords();

#endif //LIBADAPTER_H
