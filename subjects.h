#ifndef SUBJECTS_H
#define SUBJECTS_H

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif

#include "item.h"


class Artifact : public Item {
public:
    Artifact(std::string, std::string, short, short);
    short GetPower() const ;
private:
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

class Creature : public Item, public Movable {
public:
    Creature(std::string, std::string, short, short, coord);
};

class Hero : public Creature {
public:
    Hero(std::string, std::string, short, short, coord, Storage*);
    Storage* GetInventory() const;
protected:
    Storage *inventory;
};

#endif //SUBJECTS_H
