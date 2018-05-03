#include "parser.h"
#include "libs/json.hpp"
#include <fstream>

//for error printing, should be changed to QT error printer
#include <iostream>
using std::cout;
using std::endl;

using json = nlohmann::json;
using std::vector;

void from_json(const json &j, coord &c) {
    c.x = j.at("x").get<int>();
    c.y = j.at("y").get<int>();
}

void from_json(const json &j, actionData &action) {
    str object_id = "", condition = "";
    auto subject_id = j.at("subject_id").get<str>();
    auto command = j.at("command").get<str>();
    auto toDiary = j.at("toDiary").get<str>();
    auto duration = j.at("duration").get<short>();

    // fields 'object_id' and 'condition' can be empty
    try { object_id = j.at("object_id").get<str>();
    } catch(nlohmann::detail::out_of_range) {}

    try { condition = j.at("condition").get<str>();
    } catch(nlohmann::detail::out_of_range) {}

    action.set(subject_id, command, object_id, toDiary, condition, duration);
}

eventData* Parser::getEventData(str filename) {
    std::ifstream file(filename);
    json j;
    try {file >> j;} catch(nlohmann::detail::parse_error) {
        cout << "Error: json " << filename << " is invalid." << endl;
        return nullptr;
    }
    eventData *ev_data;
    try {
        ev_data = new eventData(
            j.at("id").get<str>(),
            j.at("name").get<str>(),
            j.at("coord").get<coord>(),
            j.at("radius").get<short>(),
            j.at("level").get<short>(),
            j.at("actions").get<std::vector<actionData>>()
        );
    } catch(nlohmann::detail::out_of_range) {
        cout << "Event from file " << filename << " is invalid." << endl;
        return nullptr;
    }
    return ev_data;
}