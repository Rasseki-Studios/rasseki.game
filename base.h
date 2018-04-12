#ifndef BASE_H
#define BASE_H

#include <string>
#include <vector>

using str = std::string;

struct coord {
    int x;
    int y;
};

class Located {
public:
    Located(int, int);
    void SetCoord(coord);
    coord GetCoord() const;
protected:
    coord coordinates;
};

class Movable : public Located {
public:
    Movable(coord, short);
    bool Move(coord);
    coord Step();
    short GetSpeed() const;
protected:
    short speed;
    std::vector<coord> path;
};

class Item {
public:
    Item(str, str, short);
    str GetId() const;
    str GetName() const;
    short GetLevel() const;
protected:
    str id;
    str name;
    short level;
};

#endif //BASE_H