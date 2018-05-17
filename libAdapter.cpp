#include "libAdapter.h"
#include <unistd.h>

coord c(200, 200);
short a = 5;
Movable hero(c,a);
bool run_flag = true;

//std::thread td;
//Storage Inventory(5);
//Hero hero("MLQ", "Moleque", 5, 4, {1,1}, &Inventory);

#include <iostream>
void Moving(int count) {
    for (int i =0 ; i< count; i++) {
        hero.Step();
        usleep(10000);
        //std::cout << hero.GetCoord().x << " | " << hero.GetCoord().y << "\n";
        //sleep();
    }
}

int Game() {
    //std::thread td(Moving);
    return 5;
}

void Exit() {
    run_flag = false;
    //td.join();
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