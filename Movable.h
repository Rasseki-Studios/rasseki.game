#ifndef MOVABLE_H
#define MOVABLE_H

#include "Located.h"
#include "SurfaceData.h"

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

class Wave {
public:
    Wave(SurfaceData *);
    void Reload();  //метод обновления информации о проходимости
    std::vector<coord> Path(coord, coord);  //составление вектора шагод
private:
    int width;
    int height;
    std::vector<std::vector<short>> map;
    SurfaceData *surface;
};

#endif //MOVABLE_H
