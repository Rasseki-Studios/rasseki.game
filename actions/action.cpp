/* by stanford */

#include <action.h>
#include <cstdlib>

// temporary solution for usleep, will be removed soon
#include <unistd.h>

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
        MakeAction();
        usleep(duration * 10000);
    }
    PrintToDiary(result);
}

bool Action::CheckCondition() const {
    return true;
}

bool Action::ThrowDice() const {
    srand(time(NULL));
    return (rand() % 100) < chance;
}

void Action::PrintToDiary(bool success) const {
    // MUST BE CHANGED TO printToDiary() !!!
    if (success) gameData.WriteToDiary(successNote);
    else gameData.WriteToDiary(failureNote);
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