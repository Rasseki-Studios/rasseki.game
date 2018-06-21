#include "storage.h"

#include "session_data.h"

#include <utility>

using std::string;
using std::make_pair;
using std::shared_ptr;

using namespace SessionData;

Storage::Storage(short count) {
    artifacts.reserve(count);   //выделение памяти под count этементов
}

void Storage::AddArtifact(str id) {  //добавить проверку на размер емкости
    std::shared_ptr<Artifact> art = artifactsData.getArtifact(id);
    std::pair<str, shared_ptr<Artifact>> art_pair = std::make_pair(id, art);
    artifacts.emplace(art_pair);
}

void Storage::RemoveArtifact(str id) {
    artifacts.erase(id);
}

int Storage::GetCount() {
    return artifacts.size();
}

shared_ptr<Artifact> Storage::GetArtifact(str id) {
    auto artifact = artifacts.find(id);
    return artifact->second;
}

std::unordered_map<std::string, std::shared_ptr<Artifact>> Storage::GetArtifacts() {
    return artifacts;
}
