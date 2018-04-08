#ifndef SUBJECTS_H
#define SUBJECTS_H

#include <vector>

#include "base.h"

class Artifact : public Item {
public:
    Artifact(string, short, short);
private:
    short power;
};

class Storage {
public:
    Storage(short);
    void AddArtifact(Artifact);
    void RemoveArtifact(short);
    Artifact GetArtifact(short);
private:
    vector<Artifact> artifacts;
};

class Creature : public Item, public Moveble {
public:
    Creature(string, short, short, coord);
};

class Hero : public Creature {
public:
    Hero(string, short, short, coord, Storage);
protected:
    Storage inventary;
};

#endif //SUBJECTS_H
