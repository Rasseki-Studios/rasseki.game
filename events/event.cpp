#include "event.h"
#include "session_data.h"
#include <unistd.h>


using namespace SessionData;

//for error printing, should be changed to QT error printer
#include <iostream>
using std::cout;
using std::endl;

Action::Action(/* Item *subj,  */str _command, str _obj,
    str _note, str _cond, short _duration) :
    // subject(subj),
    command(_command),
    objectID(_obj),
    diaryNote(_note),
    condition(_cond),
    duration(_duration) {
}

void Action::run() const {
        // "give",         // give artifact
        // "take_away",    // remove artifact
        // "wait",         // nothing
        // "fight",        // fight
        // "die"
    if (command == "give") {
        hero.GetInventory()->AddArtifact(objectID);
        //   giveArtifact()
    }
    gameData.diaryString = diaryNote;
    usleep(duration*100000);
    // if (diaryNote != "") 
}

Event::Event(str _ID, str _name, short _level, Coord _coord,
    short _radius, short _priority, std::vector<Action> _actions) :
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

void Event::run() const {
    for (auto it : actions) it.run();
}