/*  by stanford */

#include "action_factory.h"
#include "actions_config.h"
#include "session_data.h"

// for error printing, should be changed to QT error printer
#include <iostream>
using std::cout;
using std::endl;

using std::stoi;

bool ActionData::isValid() {

    cout << "checking action with type " << type << "..." << endl;

    if (chance > MAX_CHANCE_PERCENT
    ||  chance < MIN_CHANCE_PERCENT) {
        cout << "Chance is invalid." << endl;
        return 0;
    }

    if (duration > MAX_ACTION_DURATION
    ||  duration < MIN_ACTION_DURATION) {
        cout << "Invalid action duration, it can be "
             << "from " << MIN_ACTION_DURATION
             << " to " << MAX_ACTION_DURATION
             << " seconds." << endl;
        return 0;
    }

    if (successNote.empty()
    ||  failureNote.empty()
    ) {
        cout << "Diary notes can't be empty."
            //  << ", write \"default\" to choose random default phrase"
             << endl;
    }

    if (type == "give_artifact"
    ||  type == "take_artifact_away") {
        if (!SessionData::artifactsData.ArtifactExists(artifactID)) {
            cout << "Artifact with ID " << artifactID
                 << " does not exist." << endl;
            return 0;
        }
    } else if (type == "teleport") {
        if (!SessionData::surfaceData.CoordIsValid(coord)) {
            cout << "Invalid teleport destination for this location." << endl;
            return 0;
        }
    }

    return 1;
}

Action* ActionFactory::Create(ActionData &a) {

    // Action newAction;
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