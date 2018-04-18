#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(std::string, std::string, short);
    std::string GetId() const;
    std::string GetName() const;
    short GetLevel() const;
protected:
    std::string id;
    std::string name;
    short level;
};

#endif //ITEM_H
