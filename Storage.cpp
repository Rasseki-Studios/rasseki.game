#include "Things.h"

Storage::Storage(short count) {
    artifacts.reserve(count);   //выделение памяти под count этементов
}

void Storage::AddArtifact(Artifact new_artifact) {  //добавить проверку на размер емкости
    artifacts.insert(artifacts.end(), new_artifact);
}

void Storage::RemoveArtifact(std::string id) {
    std::vector<Artifact>::iterator deleted = artifacts.end();
    for (auto artifact : artifacts) {
        if (artifact.GetId() == id) {
            *deleted = artifact;
            break;
        }
    }
    artifacts.erase(deleted);
}

Artifact* Storage::GetArtifact(std::string id) {
    Artifact *searched = nullptr;
    for (auto artifact : artifacts) {
        if (artifact.GetId() == id) {
            searched = &artifact;
            break;
        }
    }
    return searched;
}
