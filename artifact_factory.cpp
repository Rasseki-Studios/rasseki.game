#ifndef ARTIFACT_FACTORY
#define ARTIFACT_FACTORY

#include <fstream>

//for error printing, should be changed to QT error printer
#include <iostream>
using std::cout;
using std::endl;

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem::v1;

#include "artifact.h"

/* DEBUG_FUNCTION */
void ArtifactData::PrintArtifactData() {
    cout << "ID: " << ID << endl;
    cout << "name: " << name << endl;
    cout << "level: " << level << endl;
    cout << "type: " << type << endl;
    cout << "powers: " << power << endl;
}

// Artifact* ArtifactFactory::Create(str filename) {
//     ArtifactData *data = parser.getData(filename);
//     if (!data) return nullptr;
//     /* CHECKING */
//     Artifact *artifact = new Artifact(
//         data->ID, data->name, data->level,
//         data->type, data->power
//     );
//     return artifact;
// }

int ArtifactFactory::InitAll(str folder, unordered_map<str, Artifact>&) {
    int artifactCount = 0;
    for (auto &it : fs::directory_iterator(folder)) {
        if (it.path().extension() == ".json") {
            tempData = parser.getData(it.path());
            if (!tempData) continue;
            for (auto it : *tempData) {
                it.PrintArtifactData();
                cout << endl;
                artifactCount++;
            }
        }
    }
    return artifactCount;
}

#endif  // ARTIFACT_FACTORY