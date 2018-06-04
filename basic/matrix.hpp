/* by stanford */

#ifndef MATRIX
#define MATRIX

#include <stdexcept>
#include <iostream>
#include <iomanip>

using std::ostream;
using std::cerr;
using std::endl;

struct Coord {
    int x;
    int y;
    Coord() = default;
    inline Coord(const Coord &coord);
    inline Coord(int, int);
    inline friend bool operator==(const Coord& left, const Coord& right);
    inline friend ostream& operator<<(ostream&, const Coord &coord);
};

Coord::Coord(const Coord &coord) : x(coord.x), y(coord.y) {}
Coord::Coord(int _x, int _y) : x(_x), y(_y) {}

bool operator==(const Coord &left, const Coord &right) {
    return left.x == right.x && left.y == right.y;
}

ostream& operator<<(ostream &stream, const Coord &coord) {
    stream << coord.x << "," << coord.y;
    return stream;
}

/* ************************************************************************* */

template <typename T> class Matrix;
template <typename T> ostream& operator<<(ostream&, const Matrix<T>&);

template <typename T>
class Matrix {
public:
    Matrix(const int _width, const int _height, const bool defaultInit = false);
    ~Matrix();
    bool CoordIsValid(const Coord &coord) const;
    int getWidth() const;
    int getHeight() const;
    // int getDistance(const Coord &first, const Coord &second) const;

    T& operator[](const Coord &coord);
    const T& operator[](const Coord &coord) const;

    /* useful for debug */
    friend ostream& operator<< <T>(ostream& stream, const Matrix<T> &matrix);

private:
    T **array;
    int width;
    int height;
};

template <typename T>
Matrix<T>::Matrix(const int _width, const int _height, const bool defaultInit)
: width(_width), height(_height) {
    array = new T*[width];
    if (!defaultInit) {
        for (int i = 0; i != width; i++) array[i] = new T[height];
    } else {
        for (int i = 0; i != width; i++) array[i] = new T[height]();
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i != width; i++)
        delete [] array[i];
    delete [] array;
}

template <typename T>
bool Matrix<T>::CoordIsValid(const Coord &coord) const {
    return
        (coord.x < width && coord.x >= 0) &&
        (coord.y < height && coord.y >= 0);
}

template <typename T>
T& Matrix<T>::operator[](const Coord &coord) {
    if (!CoordIsValid(coord)) {
        cerr << "writing coordinate " << coord.x << "," << coord.y << endl;
        cerr << "max coordinate is " << width - 1 << "," << height - 1 << endl;
        throw std::out_of_range( " writing failed " );
    }
    return array[coord.x][coord.y];
}

template <typename T>
const T& Matrix<T>::operator[](const Coord &coord) const {
    if (!CoordIsValid(coord)) {
        cerr << "reading coordinate " << coord.x - 1 << "," << coord.y - 1 << endl;
        cerr << "max coordinate is " << width - 1 << "," << height - 1 << endl;
        throw std::out_of_range( " reading filed " );
    }
    return array[coord.x][coord.y];
}

template <typename T>
ostream& operator<<(ostream &stream, const Matrix<T> &matrix) {
    for (int i = 0; i != matrix.width; i++) {
        for (int j = 0; j != matrix.height; j++)
            stream << std::setw(3) << std::left << (int)matrix.array[i][j] << " ";
        stream << endl;
    }
    return stream;
}

template <typename T>
int Matrix<T>::getWidth() const {
    return width;
}

template <typename T>
int Matrix<T>::getHeight() const {
    return height;
}

#endif