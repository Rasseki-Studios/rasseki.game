#ifndef BASE_H
#define BASE_H

#include <string>
#include <vector>

using str = std::string;

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
    Item(str, short);
    short GetId() const;
    str GetName() const;
    short GetLevel() const;
protected:
    short id;
    str name;
    short level;
};

class Action {
public:
    Action(short, str, str, str, str);
    void run() const;
private:
    short duration;
    str subjectID;  // Item *subject in future
    str command;  // Converts in function in run()
    str objectID;  // Item *object in future
    str diaryNote;
};

class IFactory {
    virtual Item create();
    // virtual void update();
};

#endif  // BASE_H
