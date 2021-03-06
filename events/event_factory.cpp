/* by stanford */

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

//for error printing, should be changed to QT error printer
#include <iostream>
using std::cout;
using std::endl;

#include "event_factory.h"
#include "events_config.h"

#include "session_data.h"
using SessionData::eventsData;
using SessionData::surfaceData;

bool EventData::isValid() {
    cout << "Checking event \"" << std::setw(28)
         << std::left << ID + "\"... ";

    if (eventsData.EventExists(ID)) {
        cout << "FAIL" << endl;
        cout << "Event with ID " << ID 
             << " already exists." << endl;
        return false;
    } else if (level <= 0) {
        cout << "FAIL" << endl;
        cout << "Level is not valid." << endl;
        return false;
    } else if (priority > MAX_EVENT_PRIORITY && priority <= MIN_EVENT_PRIORITY) {
        cout << "FAIL" << endl;
        cout << "Invalid priority. It can be between " 
             << MIN_EVENT_PRIORITY << " and "
             << MAX_EVENT_PRIORITY << endl;
        return false;
    } else if (!surfaceData.RadiusIsValid(coordinate, radius)) {
        cout << "FAIL" << endl;
        cout << "Radius or coord are not valid." << endl;
        return false;
    }
    for (auto it : actions) {
        if (!it.isValid()) {
            actions.clear();
            return false;
        }
    }
    cout << "OK" << endl;
    return true;
}

Event& EventFactory::Create(EventData &ev_data) {
    vector<unique_ptr<Action>> actions;
    for (auto it : ev_data.actions) {
        auto newAction = actionFactory.Create(it);
        actions.push_back( move(newAction) );
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
        tempData = eventParser.getData(it.path().string());
        if (!tempData) continue;
        for (auto it : *tempData) {
            if (!it.isValid()) continue;
            Event &ev = Create(it);
            eventsMap.emplace(it.ID, move(ev));
            eventCount++;
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
