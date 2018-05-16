#include "libAdapter.h"

coord c(30,30);
short a = 5;
Movable mov(c,a);
//Storage Inventory(5);
//Hero hero("MLQ", "Moleque", 5, 4, {1,1}, &Inventory);

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
    return mov.Move({x, y});
}