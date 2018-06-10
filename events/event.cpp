#include "event.h"
#include "session_data.h"

using namespace SessionData;

Event::Event(str _ID, str _name, short _level, Coord _coord,
    short _radius, short _priority, std::vector<Action*> _actions) :
    Located(_coord),
    Item(_ID, _name, _level),
    radius(_radius),
    priority(_priority),
    actions(_actions) {
}

short Event::getRadius() {
    return radius;
}

short Event::getPriority() {
    return priority;
}

void Event::Run() const {
    for (auto it : actions) it->Run();
}