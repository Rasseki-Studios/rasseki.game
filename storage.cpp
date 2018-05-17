#include "storage.h"
#include "session_data.h"

using namespace SessionData;

void Storage::AddArtifact(str ID) {
    Artifact *art = artifactsData.getArtifact(ID);
    artifacts.push_back(art);
}