#include <experimental/filesystem>

//for error printing, should be changed to QT error printer
#include <iostream>
using std::cout;
using std::endl;

#include "event_factory.h"

namespace fs = std::experimental::filesystem::v1;

// EventFactory::EventFactory() : parser() {}

Event* EventFactory::Create(str filename) {
    auto ev_data = parser.getData(filename);
    /* needs SessionData  */
    /*     mouseartiom    */
    /*      write it!    */
    ev_data->PrintEventData();
    return nullptr;
}

int EventFactory::InitAll(str eventsPath) {
    int eventCount = 0;
    for (auto &it : fs::directory_iterator(eventsPath)) {
        if (it.path().extension() == ".json") {
            Event *event = Create(it.path());
            eventCount++;
        }
    }
    return eventCount;
}

void ActionData::set(
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
void ActionData::PrintActionData() {
    cout << "condition: " << condition << endl;
    cout << "subjectID: " << subjectID << endl;
    cout << "command: " << command << endl;  // Converts in function in run()
    cout << "objectID: " << objectID << endl;  // Item *object in future
    cout << "diaryNote: " << diaryNote << endl;
    cout << "duration: " << duration << endl;
}

EventData::EventData(
    str _ID, str _name, coord _coord, short _rad, 
    short _level, std::vector<ActionData> _actions) 
    :
    ID(_ID), name(_name), coordinate(_coord), 
    radius(_rad), level(_level), actions(_actions) 
{}

/* DEBUG_FUNCTION */
void EventData::PrintEventData() {
    cout << "ID: " << ID << endl;
    cout << "name: " << name << endl;
    cout << "level: " << level << endl;
    cout << "coords: " << coordinate.x << ", " << coordinate.y << endl;
    cout << "radius: " << radius << endl;
    for (int i = 0; i < (int)actions.size(); i++) {
        cout << endl;
        actions[i].PrintActionData();
    }
}
