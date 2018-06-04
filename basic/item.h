#ifndef ITEM_H
#define ITEM_H

#include <string>

using str = std::string;

class Item {
public:
    Item(str, str, short);
    std::string GetId() const;
    std::string GetName() const;
    short GetLevel() const;
protected:
    std::string id;
    std::string name;
    short level;
};

struct ItemData {
    str ID, name;
    short level;
    // consists of data of Items, written with strings and integers
    // can be easily written to a file, for example, .json or .xml
    // converts to Item object in factories
};

#endif  // ITEM_H
