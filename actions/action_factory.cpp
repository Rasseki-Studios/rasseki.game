/* by stanford */

#include "action_factory.h"
#include "actions_config.h"
#include "session_data.h"

// for error printing, should be changed to QT error printer
#include <iostream>
using std::cout;
using std::endl;

using std::stoi;

bool ActionData::isValid() {

    if (actionList.find(type) == actionList.end()) {
        cout << "FAIL" << endl;
        cout << "Action type \"" << type << "\" is invalid." << endl;
        return false;
    }

    if (chance > MAX_CHANCE_PERCENT
    ||  chance < MIN_CHANCE_PERCENT) {
        cout << "FAIL" << endl;
        cout << "In action with type \"" << type
             << "\": chance is invalid." << endl;
        return false;
    }

    if (duration > MAX_ACTION_DURATION
    ||  duration < MIN_ACTION_DURATION) {
        cout << "FAIL" << endl;
        cout << "In action with type \"" << type
             << "\": invalid action duration, it can be between "
             << MIN_ACTION_DURATION << " and " << MAX_ACTION_DURATION
             << " seconds." << endl;
        return false;
    }

    if (successNote.empty()
    ||  failureNote.empty()
    ) {
        cout << "FAIL" << endl;
        cout << "In action with type \"" << type
             << "\": diary notes can't be empty." << endl;
        return false;
    }

    if (type == "give"
    ||  type == "take_away") {
        if (!SessionData::artifactsData.ArtifactExists(artifactID)) {
            cout << "FAIL" << endl;
            cout << "In action with type \"" << type
                 << "\": artifact with ID " << artifactID
                 << " does not exist." << endl;
            return false;
        }
    } else if (type == "teleport") {
        if (!SessionData::surfaceData.CoordIsValid(coord)) {
            cout << "FAIL" << endl;
            cout << "In action with type \"" << type
                 << "\": invalid teleport point for this location." << endl;
            return false;
        }
    }

    return true;
}

Action* ActionFactory::Create(ActionData &a) {
    if (a.type == "give") {
        /* create GiveArtifact action */
        auto newAction = new GiveArtifact(
            a.chance,
            a.successNote,
            a.failureNote,
            a.duration,
            a.artifactID
        );
        return newAction;
    } else if (a.type == "take_away") {
        /* create TakeAwayArtifact action */
        auto newAction = new TakeAwayArtifact(
            a.chance,
            a.successNote,
            a.failureNote,
            a.duration,
            a.artifactID
        );
        return newAction;
    } else if (a.type == "wait") {
        /* create Wait action */
        auto newAction = new Wait(
            a.chance,
            a.successNote,
            a.failureNote,
            a.duration
        );
        return newAction;
    } else if (a.type == "teleport") {
        /* create Teleport action */
        auto newAction = new Teleport(
            a.chance,
            a.successNote,
            a.failureNote,
            a.duration,
            a.coord
        );
        return newAction;
    }

    return nullptr;
}