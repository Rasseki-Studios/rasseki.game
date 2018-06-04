#include "libAdapter.h"
#include <unistd.h>

using namespace SessionData;

void Moving() {    //перемещение шагов
    Coord current = hero.GetCoord();
    for (Coord step = hero.Step(); !(current == step); step = hero.Step()) {
        /*std::shared_ptr<Event>*/Event* event = eventsData.getEvent(step);    //попытка получения события в данной точке
        current = step;
        if (event) {
            event->run();
             std::cout << "event " << event->GetName() << " was found at " 
            << hero.GetCoord() << std::endl;
        }
        usleep(step_delay);  //временая задержка
    }
}

int Game() {
    //Init(); //инициализация данных игры
    hero.SetCoord({651, 414});
    return 0;
}

Coord HeroCoords() {    //получение позиции героя
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
    if (gamedata.diaryString != "") {
        post.text = gamedata.diaryString; //сообщение
        gamedata.diaryString = "";
        post.writer = gameData.writer;
    }
    return post;  //автор сообщения
}

int Go(int x, int y) {  //перемещение героя
    gameData.writer = hero.GetName();
    if (hero.Move({x, y})) {
        gamedata.diaryString = say_go;
        Moving();
    }
    else {
        gamedata.diaryString = say_cant_go;
    }
    return 0;
}
