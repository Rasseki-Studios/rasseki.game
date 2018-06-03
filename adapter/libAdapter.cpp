#include "libAdapter.h"
#include <unistd.h>

#include "session_data.h"

using namespace SessionData;

void Moving() {    //перемещение шагов
    Coord current = hero.GetCoord();
    for (Coord step = hero.Step(); current == step; step = hero.Step()) {
        std::shared_ptr <Event> event = eventsData.getEvent();    //попытка получения события в данной точке
        if (event) {
            event->runEvent();
        }
        usleep(step_delay);  //временая задержка
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

HeroData Data() {   //отправка данных о герое
    HeroData data;
    data.name = hero.GetName();
    data.level = hero.GetLevel();
    data.speed = hero.GetSpeed();
    return data;
}

Message Write() {   //получение записей для игрового журнала
    Message post;
    if (diaryString != "") {
        post.text = diaryString; //сообщение
        diaryString = "";
        post.writer = character;
    }
    return post;  //автор сообщения
}

int Go(int x, int y) {  //перемещение героя
    writer = hero.GetName();
    if (hero.Move({x, y})) {
        diaryString = say_go;
        Moving();
    }
    else {
        diaryString = say_cant_go;
    }
    return count;
}