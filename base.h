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
    int_fast8_t speed;
};

class Item {
    int_fast8_t id;
    std::string name;
    int_fast8_t level;
};

class Action {
    int_fast8_t duration;
    std::string diaryNote;
    // universal function template
    template <class Func, class... Args> std::function<Func(Args...)> act();
};

#endif  // BASE_H