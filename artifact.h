#ifndef ARTIFACT_H
#define ARTIFACT_H

#include "item.h"

class Artifact : public Item {
public:
    Artifact(std::string, std::string, short, std::string, short);
    std::string GetType() const;
    short GetPower() const ;
private:
    str::string type;
    short power;
};

#endif //ARTIFACT_H
