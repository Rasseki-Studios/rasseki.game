#ifndef LOCATED_H
#define LOCATED_H

#include <vector>

struct coord {
    int x;
    int y;
    coord();
    coord(int, int);
};

class Located {
public:
    Located(coord);
    void SetCoord(coord);
    coord GetCoord() const;
protected:
    coord coordinates;
};

#endif //LOCATED_H
