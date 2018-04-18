#ifndef LOCATION_H
#define LOCATION_H
#include <vector>

struct coord {
    int x = 0;
    int y = 0;
    coord() = default;
    coord(int, int);
};

class Located {
public:
    Located(coord);
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

#endif //LOCATION_H
