#include "event.h"
#include <fstream>
#include "libs/json.hpp"

#include <iostream>

void Action::set(str _sID, str _command, str _objID, str _note, str _cond, short _duration) { 
    subjectID = _sID;
    command = _command;
    objectID = _objID;
    diaryNote = _note;
    condition = _cond;
    duration = _duration;
}

/* DEBUG_FUNCTION */
void Action::printActData() {
    std::cout << "condition: " << condition << std::endl;
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

/* DEBUG_FUNCTION */
/* void Event::printEvent() const {
    cout << "ID: " << ID << endl;
    cout << "name: " << name << endl;
    cout << "level: " << level << endl;
    cout << "coords: " << coordinates.x << ", " << coordinates.y << endl;
    cout << "radius: " << radius << endl;
    for (int i = 0; i < (int)actions.size(); i++) {
        actions[i].printAction();
        cout << endl;
    }
} */
