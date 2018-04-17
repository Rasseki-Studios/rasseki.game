#ifndef ITEM_H
#define ITEM_H

#ifndef STRING
#define STRING
#include <string>
#endif

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
    virtual Item* createFromJson(str filename) = 0;
    // virtual void update();
};

#endif  // ITEM_H