#ifndef THINGS_H
#define THINGS_H

#include <vector>

#include "item.h"

// System of artifact modifiers will be strongly expanded

class Artifact : public Item {
public:
    Artifact(std::string, std::string, short, short);
    short GetPower() const;
private:
    // some kind of effect description
    // effect can be applied with function GetPower()
    str modifier;
    short power;
};

class Storage {
public:
    Storage(short);
    void AddArtifact(Artifact);
    void RemoveArtifact(std::string);
    Artifact* GetArtifact(std::string);
private:
    std::vector<Artifact> artifacts;
};

#endif //THINGS_H
