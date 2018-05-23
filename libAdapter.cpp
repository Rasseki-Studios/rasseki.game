#include "libAdapter.h"
#include <unistd.h>

using namespace SessionData;


void Moving(int count) {
    for (int i =0 ; i< count; i++) {
        hero.Step();
        usleep(10000);
    }
}

int Game() {
    gameData.Init();
    SessionData::hero.SetCoord( {200, 200} );
    return 0;
}

void Exit() {

}

coord Coords() {
    coord p = hero.GetCoord();
    return p;
}

bool Save(std::string file) {
    return true;
}

void Load(std::string file) {

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