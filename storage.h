#ifndef STORAGE
#define STORAGE

#include "artifact.h"

class Storage {
public:
    void AddArtifact(str);
    // void RemoveArtifact(str);
private:
    std::vector<Artifact*> artifacts;
};

#endif //STORAGE