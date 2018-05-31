#ifndef MOVABLE
#define MOVABLE

#include <vector>
#include "surface.h"
#include "matrix.hpp"
#include "location.h"

class Movable : public virtual Located {
public:
    Movable(Coord, short);
    int Move(Coord);
    Coord Step();
    short GetSpeed() const;
protected:
    short speed;
    std::vector<Coord> path;
};

class WaveAlgorithm {
public:
    WaveAlgorithm();
    void Reload();  //метод обновления информации о проходимости
    std::vector<Coord> GetPath(Coord, Coord);  //составление вектора шагов
private:
    int width;
    int height;
    Matrix<short> *waveMap;
    const Matrix<short> *dataMap;
    const Coord neighbours[8] = {
        { 1,  0}, { 1, -1}, { 0, -1}, {-1, -1},
        {-1,  0}, {-1,  1}, { 0,  1}, { 1, -1}
    };
    std::vector<Coord> GetBackPath(/* Coord,  */Coord);
};

#endif