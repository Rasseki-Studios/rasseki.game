#ifndef MOVABLE_H
#define MOVABLE_H

#include <vector>

#include "session_data.h"
#include "surface.h"

class Movable : public virtual Located {
public:
    Movable(coord, short);
    int Move(coord);
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

#endif //MOVABLE_H
