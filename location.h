#ifndef LOCATION_H
#define LOCATION_H

struct coord {
    int x;
    int y;
    coord() = default;
    coord(int, int);
    friend bool operator==(const coord& left, const coord& right);
};

class Located {
public:
    Located() {};
    Located(coord);
    void SetCoord(coord);
    coord GetCoord() const;
protected:
    coord coordinates;
};

#endif //LOCATION_H
