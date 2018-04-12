#ifndef LOCATED_H
#define LOCATED_H


struct coord {
    int x;
    int y;
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
