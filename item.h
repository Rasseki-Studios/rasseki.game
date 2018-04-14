#ifndef BASE_H
#define BASE_H

#include <string>

using str = std::string;

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

class ItemFactory {
    virtual Item* getFromJson(str filename) = 0;
    // virtual void update();
};

#endif  // BASE_H