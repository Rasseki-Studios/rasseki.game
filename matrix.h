/* by stanford */

#include "location.h"

template <typename T>
class Matrix {
public:
    Matrix(const int _width, const int _height, const bool defaultInit = false);
    ~Matrix();
    T getValue(const Coord) const;
    void setValue(const Coord, T);
    bool CoordIsValid(const Coord) const;
private:
    T **array;
    int height;
    int width;
};