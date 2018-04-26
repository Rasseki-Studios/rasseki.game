#include <experimental/filesystem>

//for error printing, should be changed to QT error printer
#include <iostream>

#include "event_factory.h"
#include "parser.h"

namespace fs = std::experimental::filesystem::v1;

Event* EventFactory::createFromJson(str filename) {
    eventData *ev_data = Parser::getEventData(filename);
    ev_data->printEventData();
    return nullptr;
}

int EventFactory::initEventMap(str eventsPath) {
    int eventCount = 0;
    for (auto &it : fs::directory_iterator(eventsPath)) {
        if (it.path().extension() == ".json") {
            createFromJson(it.path());
            eventCount++;
        }
    }
    return eventCount;
}

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
    short _level, std::vector<actionData> _actions) 
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
