#ifndef LOCATION
#define LOCATION

struct coord {
    int x = 0;
    int y = 0;
    coord() = default;
    coord(int, int);
};

class Located {
public:
    Located();
    Located(coord);
    void SetCoord(coord);
    coord GetCoord() const;
protected:
    coord coordinates;
};

#endif  // LOCATION