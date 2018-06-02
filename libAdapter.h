#ifndef LIBADAPTER_H
#define LIBADAPTER_H

#include <vector>
#include <string>
#include <memory>

#include "location.h"
#include "surface.h"
#include "game_settings.h"
#include "russian.h"

struct Message {
    std::string writer;
    std::string text;
};

struct HeroData {
    std::string name;
    int level;
    int speed;
};

int Game();
void Moving(int);
Message Write();
int Go(int x, int y);
Coord Coords();
Coord EndOfMap();
HeroData Data();

#endif //LIBADAPTER_H
