#ifndef MOVABLE
#define MOVABLE

#include <vector>
#include "surface.h"
#include "matrix.hpp"
#include "located.h"

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


/* ************* LEE  WAVE  ALGORITHM ************** */
/* ***************** by stanford ******************* */

class WaveAlgorithm {
public:
    WaveAlgorithm();
    std::vector<Coord> GetPath(Coord, Coord);
private:
    int width;
    int height;
    const Matrix<char> &dataMap;
    const Coord neighbours[8] = {
        { 1,  0}, { 1, -1}, { 0, -1}, {-1, -1},
        {-1,  0}, {-1,  1}, { 0,  1}, { 1,  1}
    };
    Matrix<short> waveMap;
    std::vector<Coord> GetBackPath(Coord dest);
};

#endif