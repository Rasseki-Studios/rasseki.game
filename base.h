#ifndef BASE_H
#define BASE_H

#include <string>

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

class Movable : public Located {
public:
    Movable(coord, short);
    void Move(coord);
    short GetSpeed();
protected:
    short speed;
};

class Item {
public:
    Item(std::string, short);
    short GetId();
    std::string GetName();
    short GetLevel();
protected:
    short id;
    std::string name;
    short level;
};

#endif //BASE_H