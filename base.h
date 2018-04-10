#ifndef BASE_H
#define BASE_H

#include <string>
#include <functional>

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
    std::string name;
    short level;
};

class Action {
    short duration;
    std::string diaryNote;
    // universal function template
    template <class Func, class... Args> std::function<Func(Args...)> act();
};

#endif  // BASE_H