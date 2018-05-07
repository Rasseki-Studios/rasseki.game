#ifndef ITEM_H
#define ITEM_H

#include <string>
using str = std::string;

class Item {
public:
    Item(str, str, short);
    str getId() const;
    str getName() const;
    short getLevel() const;
protected:
    str ID;
    str name;
    short level;
};

struct ItemData {
    str ID, name;
    short level;
    ItemData(str, str, short);
    // consists of data of Items, written with strings and integers
    // can be easily written to a file, for example, .json or .xml
    // converts to Item object in factories
};

class ItemParser {
    // reads ItemData from files
    virtual ItemData* getData(str filename) = 0;
};

class ItemFactory {
public:
    virtual int InitAll(str folder) = 0;
    virtual Item* Create(str filename) = 0;
    // cannot write "Create(ItemData) = 0", because it's unable
    // to change argument type while overriding virtual method
};

#endif  // ITEM_H