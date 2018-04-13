#ifndef BASE_H
#define BASE_H

#include <string>
#include <vector>

using str = std::string;

struct coord {
    int x;
    int y;
    coord() = default;
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

class Movable : public Located {
public:
    Movable(coord, short);
    bool Move(coord);
    coord Step();
    short GetSpeed() const;
protected:
    short speed;
    std::vector<coord> path;
};

class Item {
public:
    Item(str, str, short);
    str GetId() const;
    str GetName() const;
    short GetLevel() const;
protected:
    str ID;
    str name;
    short level;
};

class IFactory {
    virtual Item* getFromJson(str filename) = 0;
    // virtual void update();
};

#endif  // BASE_H
