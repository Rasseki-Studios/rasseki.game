#include "libAdapter.h"

int Game() {
    return 17;
}

bool Save(std::string file) {
    return true;
}

void Load(std::string file) {

}

std::vector<std::string> GetSavedNames() {

}


bool Go(int x, int y) {
    return hero.Move({x, y});
}