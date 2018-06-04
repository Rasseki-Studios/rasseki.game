#ifndef LIBADAPTER_H
#define LIBADAPTER_H

#include <vector>
#include <string>
#include <memory>

#include "items_data.h"
#include "russian.h"
#include "game_settings.h"
#include "session_data.h"

struct Message {    //структура для передачи сообщения
    std::string writer; //автор
    std::string text;   //текст
};

struct HeroData {   //структура с данными о герое
    std::string name;
    int level;
    int speed;
};

int Game();
void Moving();
Message Write();
int Go(int x, int y);
Coord HeroCoords();
Coord EndOfMap();
HeroData Data();

#endif //LIBADAPTER_H