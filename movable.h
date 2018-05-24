#ifndef MOVABLE
#define MOVABLE

#include <vector>
#include "surface.h"

// using namespace SessionData;

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

class WaveAlgorithm {
public:
    WaveAlgorithm();
    void Reload();  //метод обновления информации о проходимости
    std::vector<coord> GetPath(coord, coord);  //составление вектора шагов
private:
    int width;
    int height;
    short **waveMap;
    const short **dataMap;
    const coord neighbours[8] = {
        { 1,  0}, { 1, -1}, { 0, -1}, {-1, -1},
        {-1,  0}, {-1,  1}, { 0,  1}, { 1, -1}
    };
    std::vector<coord> GetBackPath(coord, coord);
};

#endif