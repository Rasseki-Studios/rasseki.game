#include "storage.h"

#include "session_data.h"

using namespace SessionData;

Storage::Storage(short count) {
    artifacts.reserve(count);   //выделение памяти под count этементов
}

void Storage::AddArtifact(std::string id) {  //добавить проверку на размер емкости
    // std::shared_ptr<Artifact> art = artifactsData.getArtifact(id);
    // artifacts.push_back(art);
}

void Storage::RemoveArtifact(std::string id) {
    auto deleted = artifacts.end();
    for (auto artifact : artifacts) {
        if (artifact->GetId() == id) {
            *deleted = artifact;
            break;
        }
    }
    artifacts.erase(deleted);
}

std::shared_ptr<Artifact> Storage::GetArtifact(std::string id) {
    std::shared_ptr<Artifact> searched;
    for (auto artifact : artifacts) {
        if (artifact->GetId() == id) {
            searched = artifact;
            break;
        }
    }
    return searched;
}