#include "event.h"
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

Event* EventFactory::create() {
    std::ifstream i("event.json");
    json j;
    i >> j;
}

// Event::Event() {

// }

// void Event::runEvent() {
//     for (int i = 0; i < eventActions.size(); i++) {
//         eventActions[i].act();
//     }
// }