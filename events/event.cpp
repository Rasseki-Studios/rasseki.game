/* by stanford */

#include "event.h"
#include "session_data.h"

using namespace SessionData;

Event::Event(str _ID, str _name, short _level, Coord _coord,
    short _radius, short _priority, vector<unique_ptr<Action>>& _actions) :
    Located(_coord),
    Item(_ID, _name, _level),
    radius(_radius),
    priority(_priority),
    actions(move(_actions)) {
}

short Event::getRadius() const {
    return radius;
}

short Event::getPriority() const {
    return priority;
}

void Event::Run() const {
    for (auto const& it : actions) it->Run();
}