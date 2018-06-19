#include "libAdapter.h"
#include <unistd.h>

using namespace SessionData;

void Moving() {    //перемещение шагов
    Coord current = hero.GetCoord();
    for (Coord step = hero.Step(); !(current == step) && gameData.tdWorking; step = hero.Step()) {
        std::shared_ptr<Event> event = eventsData.getEvent(step);    //попытка получения события в данной точке
        if (event) {
            event->Run();
            eventsData.RemoveFrontEvent(hero.GetCoord());
        }
        std::chrono::milliseconds ms(step_delay / surfaceData.getSurfSpeed(current));
        std::this_thread::sleep_for(ms);  //временая задержка
    }
}

int Game() {
    Init(); //инициализация данных игры
    return 0;
}

Coord HeroCoords() {    //получение позиции героя
    return hero.GetCoord();
}

Coord EndOfMap() {  //получение границ карты
    return {surfaceData.getWidth(), surfaceData.getHeight()};
}

HeroData HData() {   //отправка данных о герое
    HeroData data;
    data.name = hero.GetName();
    data.level = hero.GetLevel();
    data.speed = hero.GetSpeed();
    return data;
}

bool IData(std::vector<InventoryData> &pack) {
    if (gameData.changeInventory) { //если содержимое инвентаря изменилось
        auto artifacts = hero.GetInventory()->GetArtifacts();
        for (auto artifact : artifacts) {
            InventoryData note;
            note.name = artifact->GetName();
            note.level = artifact->GetLevel();
            note.power = artifact->GetPower();
            note.type = artifact->GetType();
            pack.push_back(note);
        }
        gameData.changeInventory = false;
        return true;
    }
    else {
        return false;
    }
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
    gameData.tdWorking = true;
    gameData.writer = hero.GetName();
    if (hero.Move({x, y})) {
        gameData.diaryString = say_go;
        Moving();
    }
    else {
        gameData.diaryString = say_cant_go;
    }
    return 0;
}

void StopThread() { //остановка потока теремещения
    gameData.tdWorking = false;
}