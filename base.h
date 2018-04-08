#ifndef BASE_H
#define BASE_H

//------------------
#include <iostream>
#include <string>
using namespace std;
//------------------

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

class Moveble : public Located {
public:
    Moveble(int, int);
    void Move(coord);
protected:
    short speed;
};

class Item {
protected:
    short id;
    string name;
    short level;
};

#endif //BASE_H