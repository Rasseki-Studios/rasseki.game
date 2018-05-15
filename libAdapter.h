#ifndef RASSEKI_GAME_LIBADAPTER_H
#define RASSEKI_GAME_LIBADAPTER_H

#include <vector>
#include <string>

int Game();
bool Save(std::string);
void Load(std::string);
std::vector<std::string> GetSavedNames();

int Go(int x, int y);

#endif //RASSEKI_GAME_LIBADAPTER_H
