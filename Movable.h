#ifndef MOVABLE_H
#define MOVABLE_H


#include <vector>

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
};


#endif //MOVABLE_H
