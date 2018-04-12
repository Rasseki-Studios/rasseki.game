#ifndef STORAGE_H
#define STORAGE_H


#include <vector>

#include "Artifact.h"

class Storage {
public:
    Storage(short);
    void AddArtifact(Artifact);
    void RemoveArtifact(std::string);
    Artifact* GetArtifact(std::string);
private:
    std::vector<Artifact> artifacts;
};


#endif //STORAGE_H
