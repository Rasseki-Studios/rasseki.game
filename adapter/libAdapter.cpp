#include "libAdapter.h"
#include <chrono>
#include <thread>

using namespace SessionData;

void Moving() {    //перемещение шагов
    Coord current = gameData.hero.GetCoord();
    for (Coord step = gameData.hero.Step(); !(current == step) && gameData.tdWorking; step = gameData.hero.Step()) {
        /*std::shared_ptr<Event>*/Event* event = eventsData.getEvent(step);    
        //попытка получения события в данной точке
        current = step;
        if (event) {
            event->Run();
             std::cout << "event " << event->GetName() << " was found at " 
            << gameData.hero.GetCoord() << std::endl;
            eventsData.RemoveFrontEvent(gameData.hero.GetCoord());
        }
        std::chrono::milliseconds ms(1000 / surfaceData.getSurfSpeed(current));
        std::this_thread::sleep_for(ms);
    }
}

int Game() {
    //Init(); //инициализация данных игры
    gameData.hero.SetCoord({624, 819});
    return 0;
}

Coord HeroCoords() {    //получение позиции героя
    return gameData.hero.GetCoord();
}

Coord EndOfMap() {  //получение границ карты
    return {surfaceData.getWidth(), surfaceData.getHeight()};
}

HeroData HData() {   //отправка данных о герое
    HeroData data;
    data.name = gameData.hero.GetName();
    data.level = gameData.hero.GetLevel();
    data.speed = gameData.hero.GetSpeed();
    return data;
}

bool IData(std::vector<InventoryData> &pack) {
    if (gameData.changeInventory) {
        //std::vector<InventoryData> pack;
        auto artifacts = gameData.hero.GetInventory()->GetArtifacts();
        for (auto artifact : artifacts) {
            InventoryData note;
            note.name = artifact->GetName();
            note.level = artifact->GetLevel();
            note.power = artifact->ApplyModifier(); //GetPower();
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
    if (gameData.diaryString != "") {
        post.text = gameData.diaryString; //сообщение
        gameData.diaryString = "";
        post.writer = gameData.writer;
    }
    return post;  //автор сообщения
}

int Go(int x, int y) {  //перемещение героя
    gameData.tdWorking = true;
    gameData.writer = gameData.hero.GetName();
    if (gameData.hero.Move({x, y})) {
        gameData.diaryString = say_go;
        Moving();
    }
    else {
        gameData.diaryString = say_cant_go;
    }
    return 0;
}

void StopThread() {
    gameData.tdWorking = false;
}
