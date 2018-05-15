#ifndef MOVABLE_H
#define MOVABLE_H

#include "Located.h"

class Movable : public Located {
public:
    Movable(coord, short);
    bool Move(coord);
    coord Step();
    short GetSpeed() const;
protected:
    short speed;
    std::vector<coord> path;

    int wave(int**, int, int, coord);
};

#endif //MOVABLE_H
