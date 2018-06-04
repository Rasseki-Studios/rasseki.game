#include "libAdapter.h"
#include <unistd.h>

#include "session_data.h"
#include "russian.h"

using namespace SessionData;

void Moving() {    //перемещение шагов
    Coord current = hero.GetCoord();
    for (Coord step = hero.Step(); current == step; step = hero.Step()) {
        /*std::shared_ptr<Event>*/Event* event = eventsData.getEvent(step);    //попытка получения события в данной точке
        current = step;
        if (event) {
            event->run();
        }
        usleep(step_delay);  //временая задержка
    }
}

int Game() {
    //Init(); //инициализация данных игры
    return 0;
}

Coord Coords() {    //получение позиции героя
    return hero.GetCoord();
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
        post.writer = writer;
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
    return 0;
}
