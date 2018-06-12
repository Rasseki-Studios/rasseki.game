/*  by stanford */

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

//for error printing, should be changed to QT error printer
#include <iostream>
using std::cout;
using std::endl;

#include "session_data.h"
#include "event_factory.h"

using namespace SessionData;

bool EventData::isValid() {

    cout << "checking event with ID " << ID << "..." << endl;

    if (eventsData.EventExists(ID)) {
        cout << "event with ID " << ID 
             << " already exists" << endl;
        return 0;
    } else if (level <= 0) {
        cout << "level is not valid" << endl;
        return 0;
    } else if (priority > 6 && priority <= 0) {
        cout << "level is not valid" << endl;
        return 0;
    } else if (!surfaceData.RadiusIsValid(coordinate, radius)) {
        cout << "radius or coord are not valid" << endl;
        return 0;
    }
    for (auto it : actions) {
        if (!it.isValid()) {
            cout << "action in event " << ID << " is invalid" << endl;
            actions.clear();
            return 0;
        }
    }
    return 1;
}

Event& EventFactory::Create(EventData &ev_data) {
    vector<Action *> actions;
    for (auto it : ev_data.actions) {
        auto newAction = actionFactory.Create(it);
        actions.push_back(newAction);
    }
    Event *ev = new Event(
        ev_data.ID, ev_data.name, ev_data.level,
        ev_data.coordinate, ev_data.radius, 
        ev_data.priority, actions
    );

    return *ev;
}

int EventFactory::InitAll(str folder, unordered_map<str, Event> &eventsMap) {
    int eventCount = 0;
    for (auto &it : fs::directory_iterator(folder)) {
        if (it.path().extension() == ".json") {
            tempData = eventParser.getData(it.path().string());
            if (!tempData) continue;
            for (auto it : *tempData) {
                // checking if event with this ID is already read
                if (it.isValid()) {
                    Event &ev = Create(it);
                    eventsMap.emplace(it.ID, ev);
                    eventCount++;
                    cout << "event <" << it.ID << "> read." << endl;
                } else {
                    cout << "event <" << it.ID << "> not read." << endl;
                    continue;
                }
            }
        }
    }
    return eventCount;
}

void EventData::set(
    str _ID, str _name, short _level, Coord _coord,
    short _rad, short _priority, std::vector<ActionData> _actions) {

    ID =_ID;
    name = _name;
    level = _level;
    priority = _priority;
    coordinate = _coord;
    radius = _rad;
    actions = _actions;
}
