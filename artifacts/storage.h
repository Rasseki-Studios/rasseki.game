#ifndef STORAGE_H
#define STORAGE_H

#include <memory>
#include <vector>

#include "artifact.h"

class Storage {
public:
    Storage() = default;
    Storage(short);
    void AddArtifact(std::string);
    void RemoveArtifact(std::string);
    int GetCount();
    std::shared_ptr<Artifact> GetArtifact(std::string);
    std::vector<std::shared_ptr<Artifact>> GetArtifacts();
private:
    std::vector<std::shared_ptr<Artifact>> artifacts;
};

#endif //STORAGE_H
