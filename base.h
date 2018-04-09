#ifndef ADD_H
#define ADD_H

#include <string>
using namespace std;

struct coord {
    int x;
    int y;
};

class Located {
public:
    Located(int, int);
    coord GetCoord();
    void SetCoord(coord);
protected:
    coord coordinates;
};

class Movable : Located {
public:
    Movable(int, int);
    void Move(coord);
protected:
    short speed;
};

class Item {
    short id;
    string name;
    short level;
};

#endif