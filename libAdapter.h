#ifndef LIBADAPTER_H
#define LIBADAPTER_H

#include <vector>
#include <string>

#include "Storage.h"
#include "Hero.h"

Storage Inventory(5);
Hero hero("MLQ", "Moleque", 5, 4, {1,1}, &Inventory);

int Game();
bool Save(std::string);
void Load(std::string);
std::vector<std::string> GetSavedNames();
bool Go(int x, int y);

#endif //LIBADAPTER_H
