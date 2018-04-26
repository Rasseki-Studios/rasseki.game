#include "parser.h"
#include "libs/json.hpp"
#include <fstream>

//for error printing, should be changed to QT error printer
#include <iostream>

using json = nlohmann::json;
using std::vector;

using std::cout;
using std::endl;

void actionData::set(
    str _subjectID, str _command, str _objectID, 
    str _toDiary, str _condition, short _duration) {

    subjectID = _subjectID;
    command = _command;
    objectID = _objectID; 
    diaryNote = _toDiary; 
    condition = _condition;
    duration = _duration;
}

/* DEBUG_FUNCTION */
void actionData::printActionData() {
    std::cout << "condition: " << condition << std::endl;
    std::cout << "subjectID: " << subjectID << std::endl;
    std::cout << "command: " << command << std::endl;  // Converts in function in run()
    std::cout << "objectID: " << objectID << std::endl;  // Item *object in future
    std::cout << "diaryNote: " << diaryNote << std::endl;
    std::cout << "duration: " << duration << std::endl;
}

eventData::eventData(
    str _ID, str _name, coord _coord, short _rad, 
    short _level, vector<actionData> _actions) 
    :
    ID(_ID), name(_name), coordinate(_coord), 
    radius(_rad), level(_level), actions(_actions) 
{}

/* DEBUG_FUNCTION */
void eventData::printEventData() {
    std::cout << "ID: " << ID << std::endl;
    std::cout << "name: " << name << std::endl;
    std::cout << "level: " << level << std::endl;
    std::cout << "coords: " << coordinate.x << ", " << coordinate.y << std::endl;
    std::cout << "radius: " << radius << std::endl;
    for (int i = 0; i < (int)actions.size(); i++) {
        std::cout << std::endl;
        actions[i].printActionData();
    }
}

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
        std::cout << "Error: json " << filename << " is invalid." << std::endl;
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
        std::cout << "Event from file " << filename << " is invalid." << std::endl;
        return nullptr;
    }
    return ev_data;
}