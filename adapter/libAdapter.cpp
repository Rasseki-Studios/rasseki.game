#include "libAdapter.h"
#include <unistd.h>

#include "session_data.h"

using namespace SessionData;

void Moving(int count) {
    for (int i = 0 ; i < count; i++) {
        hero.Step(); // returns coord
        Event *event = eventsData.getEvent(hero.GetCoord());
        if (event) {
            // event->runEvent();
            std::cout << "event " << event->GetName() << " was found at " 
            << hero.GetCoord() << std::endl;
            eventsData.RemoveFrontEvent(hero.GetCoord());

        }
        usleep(10000);
    }
}

int Game() {
    hero.SetCoord({651, 414});
    return 0;
}

Coord Coords() {
    Coord p = hero.GetCoord();
    return p;
}

Coord EndOfMap() {
    return {surfaceData.getWidth(), surfaceData.getHeight()};
}

std::vector<str> Data() {
    std::vector<str> data;
    data.push_back(hero.GetName());
    data.push_back(std::to_string(hero.GetLevel()));
    data.push_back(std::to_string(hero.GetSpeed()));
    return data;
}

bool Save(std::string file) {
    return true;
}

void Load(std::string file) {

}

std::string Write(std::string *msg) {
    if (diaryString != "") {
        *msg = diaryString;
        diaryString = "";
    }
    return writer;
}

std::vector<std::string> GetSavedNames() {

}

int Go(int x, int y) {
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