#ifndef MOVABLE
#define MOVABLE

#include <vector>
#include "surface.h"

// using namespace SessionData;

class Movable : public virtual Located {
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
    Wave();
    void Reload();  //метод обновления информации о проходимости
    std::vector<coord> Path(coord, coord);  //составление вектора шагод
private:
    int width;
    int height;
    std::vector<std::vector<short>> map;
};

#endif