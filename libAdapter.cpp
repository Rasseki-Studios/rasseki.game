#include "libAdapter.h"
#include <unistd.h>

#include "session_data.h"
#include "items_data.h"

using namespace SessionData;

void Moving(int count) {
    for (int i =0 ; i< count; i++) {
        Event *event = eventsData.getEvent(hero.Step());
        if (event != nullptr) {
            event->runEvent();
        }
        /*try {
            event.runEvent();
        }
        catch () {

        }*/
        usleep(10000);
    }
}

int Game() {
    gameData.Init();
    hero.SetCoord({637, 712});
    return 0;
}

void Exit() {

}

coord Coords() {
    coord p = hero.GetCoord();
    return p;
}

std::string Name() {
    return hero.GetName();
}

bool Save(std::string file) {
    return true;
}

void Load(std::string file) {

}

std::string Write() {
    //while (!message);
    return "ok";//message;
}

std::vector<std::string> GetSavedNames() {

}

int Go(int x, int y) {
    int count = 0;
    if ((count = hero.Move({x, y}))) {
        Moving(count);
        //std::thread td(Moving, count);
        //td.join();
    }
    return count;
}