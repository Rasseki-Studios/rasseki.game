#ifndef ITEM_H
#define ITEM_H

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
    virtual int InitAll(str path) = 0;
    virtual Item* CreateOne(str filename) = 0;
    // virtual void update();
};

#endif  // ITEM_H