#include "event.h"
#include <fstream>
#include "libs/json.hpp"
#include "vector"

#include <iostream>

void Action::set(str _sID, str _command, str _objID, str _note, short _duration) { 
    subjectID = _sID;
    command = _command;
    objectID = _objID;
    diaryNote = _note;
    duration = _duration;
}

/* DEBUG_FUNCTION */
void Action::printActData() {
    std::cout << "subjectID: " << subjectID << std::endl;
    std::cout << "command: " << command << std::endl;  // Converts in function in run()
    std::cout << "objectID: " << objectID << std::endl;  // Item *object in future
    std::cout << "diaryNote: " << diaryNote << std::endl;
    std::cout << "duration: " << duration << std::endl;
}

Event::Event(str _ID, str _name, short _level, 
    coord _coord, short _radius, std::vector<Action> _actions) :
    Item(_ID, _name, _level),
    Located(_coord),
    radius(_radius),
    actions(_actions) {
}

void from_json(const json &j, coord &c) {
    c.x = j.at("x").get<int>();
    c.y = j.at("y").get<int>();
}

void from_json(const json &j, Action &action) {
    action.set(
        j.at("subject_id").get<str>(),
        j.at("command").get<str>(),
        j.at("object_id").get<str>(),
        j.at("toDiary").get<str>(),
        j.at("duration").get<short>()
    );
}

Event* EventFactory::getFromJson(str filename) {
    std::ifstream file(filename);
    json j;
    file >> j;
    Event *ev = new Event(
        j.at("ID").get<str>(),
        j.at("name").get<str>(),
        j.at("level").get<short>(),
        j.at("coord").get<coord>(),
        j.at("radius").get<short>(),
        j.at("actions").get<std::vector<Action>>()
    );
    return ev;
}

/* DEBUG_FUNCTION */
void Event::printEvData() {
    std::cout << "ID: " << ID << std::endl;
    std::cout << "name: " << name << std::endl;
    std::cout << "level: " << level << std::endl;
    std::cout << "coords: " << coordinates.x << ", " << coordinates.y << std::endl;
    std::cout << "radius: " << radius << std::endl;
    for (int i = 0; i < (int)actions.size(); i++) {
        actions[i].printActData();
        std::cout << std::endl;
    }
}