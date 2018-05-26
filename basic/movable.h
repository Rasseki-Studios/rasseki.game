#ifndef MOVABLE
#define MOVABLE

#include <vector>
#include "surface.h"

// using namespace SessionData;

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
    short **waveMap;
    const short **dataMap;
    const Coord neighbours[8] = {
        { 1,  0}, { 1, -1}, { 0, -1}, {-1, -1},
        {-1,  0}, {-1,  1}, { 0,  1}, { 1, -1}
    };
    std::vector<Coord> GetBackPath(/* Coord,  */Coord);
};

#endif