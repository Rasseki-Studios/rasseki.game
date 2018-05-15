#ifndef ARTIFACT_H
#define ARTIFACT_H

#include <vector>

#include "Item.h"

class Artifact : public Item {
public:
    Artifact(std::string, std::string, short, short);
    short GetPower() const ;
private:
    short power;
};

#endif //ARTIFACT_H
