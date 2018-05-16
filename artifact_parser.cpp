#ifndef ARTIFACT_PARSER
#define ARTIFACT_PARSER

#include <fstream>

//for error printing, should be changed to QT error printer
#include <iostream>
using std::cout;
using std::endl;

#include "artifact.h"

#include "libs/json.hpp"
using json = nlohmann::json;

void from_json(const json &j, ArtifactData &artifact) {
    auto id =  j.at("id").get<str>();
    auto name = j.at("name").get<str>();
    auto level = j.at("level").get<short>();
    auto type = j.at("type").get<str>();
    auto power = j.at("power").get<short>();

    artifact.set(id, name, level, type, power);
}

shared_ptr<vector<ArtifactData>> ArtifactParser::getData(str filename) {
    shared_ptr<vector<ArtifactData>> art_data;
    std::ifstream file(filename);
    json j;
    try { file >> j; } catch(nlohmann::detail::parse_error) {
        cout << "Error: json " << filename << " is invalid." << endl;
        return nullptr;
    }
    try {
        auto art_data_vector = j.at("artifacts").get<std::vector<ArtifactData>>();
        art_data = make_shared<vector<ArtifactData>>(art_data_vector);
    } catch(nlohmann::detail::out_of_range) {
        cout << "Artifacts from file " << filename << " are invalid." << endl;
        return nullptr;
    }
    return art_data;
}

#endif  // ARTIFACT_PARSER