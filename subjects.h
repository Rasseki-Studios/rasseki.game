#ifndef SUBJECTS_H
#define SUBJECTS_H

#include <vector>

#include "base.h"

class Artifact : public Item {
public:
    Artifact(std::string, short, short);
    short GetPower();
private:
    short power;
};

class Storage {
public:
    Storage(short);
    void AddArtifact(Artifact);
    void RemoveArtifact(short);
    Artifact* GetArtifact(short);
private:
    std::vector<Artifact> artifacts;
};

class Creature : public Item, public Movable {
public:
    Creature(std::string, short, short, coord);
};

class Hero : public Creature {
public:
    Hero(std::string, short, short, coord, Storage*);
    Storage* GetInventary();
protected:
    Storage *inventary;
};

#endif //SUBJECTS_H
