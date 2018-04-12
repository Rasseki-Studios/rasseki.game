#include "event.h"
#include <fstream>
#include "json.hpp"

#include <iostream>

using json = nlohmann::json;

Event::Event(str _ID, str _name, short _level, coord _coord, short _radius) :
    Item(_ID, _name, _level),
    Located(_coord),
    radius(_radius) {
}

Event* EventFactory::create() {
    std::ifstream file("event2.json");
    json j;
    file >> j;
    Event *ev = new Event(
        j.at("ID").get<str>(),
        j.at("name").get<str>(),
        j.at("level").get<short>(),
        coord(1, 2),
        j.at("radius").get<short>()
    );
    return ev;
}

void Event::printEvData() {
    std::cout << "ID: " << ID << std::endl;
    std::cout << "name: " << name << std::endl;
    std::cout << "level: " << level << std::endl;
    std::cout << "radius: " << radius << std::endl;
}

// void Event::runEvent() {
//     for (int i = 0; i < eventActions.size(); i++) {
//         eventActions[i].act();
//     }
// }