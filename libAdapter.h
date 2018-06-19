#ifndef LIBADAPTER_H
#define LIBADAPTER_H

#include <vector>
#include <string>
#include <memory>
#include <chrono>

#include "items_data.h"
#include "russian.h"
#include "config.h"
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

struct InventoryData {  //структура с данными об артифакте
    std::string name;
    int level;
    int power;
    std::string type;
};

int Game();
void Moving();
Message Write();
int Go(int x, int y);
Coord HeroCoords();
Coord EndOfMap();
HeroData HData();
bool IData(std::vector<InventoryData>&);
void StopThread();

#endif //LIBADAPTER_H