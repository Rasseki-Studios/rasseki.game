#include "libAdapter.h"
#include <unistd.h>

#include "session_data.h"

using namespace SessionData;

int const time_delay = 10000;

void Moving(int count) {    //перемещение на count шагов
        Event *event = eventsData.getEvent(hero.GetCoord());    //попытка получения события в данной точке
        if (event) {
            event->runEvent();
        }
        usleep(time_delay);  //временая задержка
    }
}

int Game() {
    Init(); //инициализация данных игры
    return 0;
}

Coord Coords() {    //получение позиции героя
    Coord place = hero.GetCoord();
    return place;
}

Coord EndOfMap() {  //получение границ карты
    return {surfaceData.getWidth(), surfaceData.getHeight()};
}

std::vector<str> Data() {   //отправка данных о герое
    std::vector<str> data;
    data.push_back(hero.GetName());
    data.push_back(std::to_string(hero.GetLevel()));
    data.push_back(std::to_string(hero.GetSpeed()));
    return data;
}

std::string Write(std::string *msg) {   //получение записей для игрового журнала
    if (diaryString != "") {
        *msg = diaryString; //сообщение
        diaryString = "";
    }
    return writer;  //автор сообщения
}

int Go(int x, int y) {  //перемещение героя
    int count = 0;
    writer = hero.GetName();
    if ((count = hero.Move({x, y}))) {
        diaryString = "Я иду...";
        Moving(count);
    }
    else {
        diaryString = "Не знаю как туда попасть=(";
    }
    return count;
}