#include "event.h"
#include "parser.h"

//for error printing, should be changed to QT error printer
#include <iostream>

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem::v1;

/* void Action::set(str _sID, str _command, str _objID, str _note, str _cond, short _duration) { 
    subjectID = _sID;
    command = _command;
    objectID = _objID;
    diaryNote = _note;
    condition = _cond;
    duration = _duration;
} */

/* DEBUG_FUNCTION */
/* void Action::printAction() {
    std::cout << "condition: " << condition << std::endl;
    std::cout << "subjectID: " << subjectID << std::endl;
    std::cout << "command: " << command << std::endl;  // Converts in function in run()
    std::cout << "objectID: " << objectID << std::endl;  // Item *object in future
    std::cout << "diaryNote: " << diaryNote << std::endl;
    std::cout << "duration: " << duration << std::endl;
} */

Event::Event(str _ID, str _name, short _level, 
    coord _coord, short _radius, std::vector<Action> _actions) :
    Item(_ID, _name, _level),
    Located(_coord),
    radius(_radius),
    actions(_actions) {
}

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

/* DEBUG_FUNCTION */
/* void Event::printEvent() {
    std::cout << "ID: " << ID << std::endl;
    std::cout << "name: " << name << std::endl;
    std::cout << "level: " << level << std::endl;
    std::cout << "coords: " << coordinates.x << ", " << coordinates.y << std::endl;
    std::cout << "radius: " << radius << std::endl;
    for (int i = 0; i < (int)actions.size(); i++) {
        actions[i].printAction();
        std::cout << std::endl;
    }
} */