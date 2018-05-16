#ifndef LIBADAPTER_H
#define LIBADAPTER_H

#include <vector>
#include <string>

#include "Movable.h"

int Game();
bool Save(std::string);
void Load(std::string);
std::vector<std::string> GetSavedNames();
bool Go(int x, int y);

#endif //LIBADAPTER_H
