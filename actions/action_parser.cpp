/* by stanford */

#include "libs/json.hpp"
using json = nlohmann::json;

#include "action_factory.h"

void from_json(const json &j, Coord &c) {
    c.x = j.at("x").get<int>();
    c.y = j.at("y").get<int>();
}

void from_json(const json &j, ActionData &action) {
    action.type        = j.at("type").get<str>();
    action.chance      = j.at("chance").get<int>();
    action.successNote = j.at("successNote").get<str>();
    action.failureNote = j.at("failureNote").get<str>();
    action.duration    = j.at("duration").get<int>();

    try { action.artifactID = j.at("artifact_id").get<str>();
    } catch(nlohmann::detail::out_of_range) {}

    try { action.coord = j.at("coordinate").get<Coord>();
    } catch(nlohmann::detail::out_of_range) {}

    // prepared for better times, when creatures will be added
    /* try { action.values["enemy_ID"] = j.at("enemy_ID").get<str>();
    } catch(nlohmann::detail::out_of_range) {} */
}