/*  by stanford */

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

//for error printing, should be changed to QT error printer
#include <iostream>
using std::cout;
using std::endl;

#include "artifact_factory.h"
#include "artifacts_config.h"

#include "session_data.h"
using SessionData::artifactsData;

bool ArtifactData::isValid() {
    cout << "Checking artifact \"" << std::setw(25)
        << std::left << ID + "\"... ";

    if (artifactsData.ArtifactExists(ID)) {
        cout << "FAIL" << endl;
        cout << "Artifact with ID " << ID
             << " already exists." << endl;
        return false;
    } else if (level <= 0) {
        cout << "FAIL" << endl;
        cout << "Level is not valid." << endl;
        return false;
    } else if (/* typeList.find(type) == typeList.end() */0) {
        cout << "FAIL" << endl;
        cout << "Type is invalid." << endl;
        return false;
    }
    cout << "OK" << endl;
    return true;
}

void ArtifactData::set(
    str _ID, str _name, short _level,
    str _type, short _power) {

    ID = _ID;
    name = _name;
    level = _level;
    type = _type;
    power = _power;
}

Artifact& ArtifactFactory::Create(ArtifactData &ar_data) {
    Artifact *artifact = new Artifact(
        ar_data.ID, ar_data.name, ar_data.level,
        ar_data.type, ar_data.power
    );
    return *artifact;
}

int ArtifactFactory::InitAll(str folder, unordered_map<str, Artifact> &artifactMap) {
    int artifactCount = 0;
    for (auto &it : fs::directory_iterator(folder)) {
        tempData = parser.getData(it.path().string());
        if (!tempData) continue;
        for (auto it : *tempData) {
            if (!it.isValid()) continue;
            Artifact &ar = Create(it);
            artifactMap.emplace(it.ID, ar);
            artifactCount++;
        }
    }
    tempData->clear();
    tempData->shrink_to_fit();
    return artifactCount;
}
