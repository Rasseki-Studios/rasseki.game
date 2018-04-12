#include "Storage.h"

Storage::Storage(short count) {
    artifacts.reserve(count);   //выделение памяти под count этементов
}

void Storage::AddArtifact(Artifact new_artifact) {  //добавить проверку на размер емкости
    artifacts.insert(artifacts.end(), new_artifact);
}

void Storage::RemoveArtifact(std::string id) {
    for (std::vector<Artifact>::iterator it = artifacts.begin(); it != artifacts.end(); it++) {
        if ((*it).GetId() == id) {
            artifacts.erase(it);
        }
    }
}

Artifact* Storage::GetArtifact(std::string id) {
    for (std::vector<Artifact>::iterator it = artifacts.begin(); it != artifacts.end(); it++) {
        if ((*it).GetId() == id) {
            return it.base();
        }
    }
    return nullptr;
}