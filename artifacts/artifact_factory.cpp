/*  by stanford */

#ifndef ARTIFACT_FACTORY
#define ARTIFACT_FACTORY

#include <fstream>
#include <utility>
#include "artifact.h"

//for error printing, should be changed to QT error printer
#include <iostream>
using std::cout;
using std::endl;

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem::v1;

using std::make_pair;

/* DEBUG_FUNCTION */
void ArtifactData::PrintArtifactData() {
    cout << "ID: " << ID << endl;
    cout << "name: " << name << endl;
    cout << "level: " << level << endl;
    cout << "type: " << type << endl;
    cout << "powers: " << power << endl;
}

bool ArtifactFactory::isValid(ArtifactData &ar_data) {
    if (/* checking if such artifact already exists */0) {
        cout << "such artifact already exists" << endl;
        return 0;
    } else if (ar_data.level <= 0) {
        cout << "level is not valid" << endl;
        return 0;
    } else if (typeList.find(ar_data.type) == typeList.end()) {
        cout << "type is invalid" << endl;
        return 0;
    } else {
        return 1;
    }
}

Artifact* ArtifactFactory::Create(ArtifactData &ar_data) {
    Artifact *artifact = new Artifact(
        ar_data.ID, ar_data.name, ar_data.level,
        ar_data.type, ar_data.power
    );
    return artifact;
}

int ArtifactFactory::InitAll(str folder, unordered_map<str, Artifact> &artifactMap) {
    int artifactCount = 0;
    for (auto &it : fs::directory_iterator(folder)) {
        if (it.path().extension() == ".json") {
            tempData = parser.getData(it.path());
            if (!tempData) continue;
            for (auto it : *tempData) {
                if (artifactMap.find(it.ID) != artifactMap.end()) continue;
                if (!isValid(it)) {
                    cout << "artifact <" << it.ID << "> not read." << endl;
                    continue;
                }
                Artifact *ar = Create(it);
                artifactMap.insert(make_pair(it.ID, *ar));
                artifactCount++;
            }
        }
    }
    for (auto it : artifactMap) {
        cout << "artifact <" << it.second.GetId() << "> read." << endl;
    }
    // delete tempData;
    return artifactCount;
}

#endif  // ARTIFACT_FACTORY