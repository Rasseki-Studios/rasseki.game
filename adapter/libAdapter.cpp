#include "libAdapter.h"
#include <chrono>
#include <thread>

using namespace SessionData;

void Moving() {    //перемещение шагов
    Coord current = hero.GetCoord();
    for (Coord step = hero.Step(); !(current == step); step = hero.Step()) {
        /*std::shared_ptr<Event>*/Event* event = eventsData.getEvent(step);    
        //попытка получения события в данной точке
        current = step;
        if (event) {
            event->Run();
             std::cout << "event " << event->GetName() << " was found at " 
            << hero.GetCoord() << std::endl;
            eventsData.RemoveFrontEvent(hero.GetCoord());
        }
        std::chrono::milliseconds ms(1000 / surfaceData.getSurfSpeed(current));
        std::this_thread::sleep_for(ms);
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

HeroData HData() {   //отправка данных о герое
    HeroData data;
    data.name = hero.GetName();
    data.level = hero.GetLevel();
    data.speed = hero.GetSpeed();
    return data;
}

bool IData(std::vector<InventoryData> &pack) {
    if (gameData.changeInventory) {
        //std::vector<InventoryData> pack;
        auto artifacts = hero.GetInventory()->GetArtifacts();
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
