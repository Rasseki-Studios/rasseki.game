#ifndef STORAGE_H
#define STORAGE_H

#include <memory>

#include "artifact.h"

class Storage {
public:
    Storage(short);
    void AddArtifact(std::string);
    void RemoveArtifact(std::string);
    std::shared_ptr<Artifact> GetArtifact(std::string);
private:
    std::vector<std::shared_ptr<Artifact>> artifacts;
};

#endif //STORAGE_H
