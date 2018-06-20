/* by stanford */

#include <cstdlib>
#include <chrono>
#include <thread>

#include "action.h"
#include "actions_config.h"

#include "session_data.h"
using namespace SessionData;

#include <iostream>
using std::cout;
using std::endl;

Action::Action(int chance, str sNote, str fNote, int dur)
: chance(chance), successNote(sNote), failureNote(fNote), duration(dur) {}

void Action::Run() const {
    bool result = ThrowDice();
    if (result) {
        gameData.WriteToDiary(successNote);
        MakeAction();
        std::chrono::milliseconds ms(duration * DURATION_FACTOR);
        std::this_thread::sleep_for(ms);
    } else {
        gameData.WriteToDiary(failureNote);
    }
}

bool Action::CheckCondition() const {
    return true;
}

bool Action::ThrowDice() const {
    srand(time(NULL));
    return (rand() % MAX_CHANCE_PERCENT) < chance;
}


GiveArtifact::GiveArtifact(
    int chance,
    str sNote, str fNote,
    int dur,
    str artID
) : Action(chance, sNote, fNote, dur), artifactID(artID) {}

void GiveArtifact::MakeAction() const {
    /* by salman */
    hero.GetInventory()->AddArtifact(artifactID);
    gameData.changeInventory = true;

    // prepared for best times, when artifact modifiers will be added
    // artifact.ApplyModifier()
}


TakeAwayArtifact::TakeAwayArtifact(
    int chance,
    str sNote, str fNote,
    int dur,
    str artID
) : Action(chance, sNote, fNote, dur), artifactID(artID) {}

void TakeAwayArtifact::MakeAction() const {
    /* by salman */
}


Teleport::Teleport(
    int chance,
    str sNote, str fNote,
    int dur,
    Coord dest
) : Action(chance, sNote, fNote, dur), destination(dest) {}

void Teleport::MakeAction() const {
    /* by salman */
}


Wait::Wait(int chance, str sNote, str fNote, int dur)
: Action(chance, sNote, fNote, dur) {}

void Wait::MakeAction() const {
    /* just waiting */
}
