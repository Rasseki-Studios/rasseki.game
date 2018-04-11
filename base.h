#ifndef BASE_H
#define BASE_H

#include <string>
#include <vector>

struct coord {
    int x;
    int y;
};

class Located {
public:
    Located(int, int);
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
    Item(std::string, short);
    short GetId() const;
    std::string GetName() const;
    short GetLevel() const;
protected:
    short id;
    std::string name;
    short level;
};

class Action {
public:
    void run() const;
private:
    short duration;
    std::string diaryNote;
};

class IFactory {
    virtual Item create();
    // virtual void update();
};

#endif  // BASE_H
