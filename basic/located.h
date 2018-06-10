#ifndef LOCATION_H
#define LOCATION_H

#include "matrix.hpp"

class Located {
public:
    Located() = default;
    Located(Coord);
    void SetCoord(Coord);
    Coord GetCoord() const;
protected:
    Coord coordinates;
};

#endif //LOCATION_H
