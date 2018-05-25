#ifndef LOCATION_H
#define LOCATION_H

struct Coord {
    int x;
    int y;
    Coord() = default;
    Coord(int, int);
    friend bool operator==(const Coord& left, const Coord& right);
};

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
