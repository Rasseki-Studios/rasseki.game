#include "event_factory.h"
#include "libs/json.hpp"
#include <fstream>

// for error printing, should be changed to QT error printer
#include <iostream>
using std::cout;
using std::endl;

using json = nlohmann::json;
using std::vector;

void from_json(const json &j, coord &c) {
    c.x = j.at("x").get<int>();
    c.y = j.at("y").get<int>();
}

void from_json(const json &j, ActionData &action) {
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

void from_json(const json &j, EventData &event) {
    auto id =  j.at("id").get<str>();
    auto name = j.at("name").get<str>();
    auto coordinate = j.at("coord").get<coord>();
    auto radius = j.at("radius").get<short>();
    auto priority = j.at("priority").get<short>();
    auto level = j.at("level").get<short>();
    auto actions = j.at("actions").get<std::vector<ActionData>>();

    event.set(id, name, level, coordinate, radius, priority, actions);
}

shared_ptr<vector<EventData>> EventParser::getData(str filename) {
    shared_ptr<vector<EventData>> ev_data;
    std::ifstream file(filename);
    json j;
    try { file >> j; } catch(nlohmann::detail::parse_error) {
        cout << "Error: json " << filename << " is invalid." << endl;
        return nullptr;
    }
    try {
        auto ev_data_vector = j.at("events").get<std::vector<EventData>>();
        ev_data = make_shared<vector<EventData>>(ev_data_vector);
    } catch(nlohmann::detail::out_of_range) {
        cout << "Events from file " << filename << " are invalid." << endl;
        return nullptr;
    }
    return ev_data;
}