#ifndef MOVABLE_H
#define MOVABLE_H

#include "Located.h"
#include "session_data.h"

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

class Wave {
public:
    Wave();
    void Reload();
    std::vector Path(coord, coord);
private:
    int width;
    int height;
    std::vector<std::vector<short>> map;
};

#endif //MOVABLE_H
