#ifndef BASE_H
#define BASE_H

#include <string>
#include <functional>
#include <vector>

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
    bool Move(coord);
    coord Step();
    short GetSpeed();
protected:
    int_fast8_t speed;
    std::vector<coord> path;
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

class Action {
    int_fast8_t duration;
    std::string diaryNote;
    // universal function template
    template <class Func, class... Args> std::function<Func(Args...)> act();
};

#endif  // BASE_H
