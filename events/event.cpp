#include "event.h"
#include "session_data.h"

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
}

/* DEBUG_FUNCTION */
/* void Action::printAction() {
    cout << "condition: " << condition << endl;
    cout << "subjectID: " << subjectID << endl;
    cout << "command: " << command << endl;
    cout << "objectID: " << objectID << endl;
    cout << "diaryNote: " << diaryNote << endl;
    cout << "duration: " << duration << endl;
} */

Event::Event(str _ID, str _name, short _level, Coord _coord,
    short _priority, short _radius, std::vector<Action> _actions) :
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

void Event::runEvent() const {

}

/* DEBUG_FUNCTION */
/* void Event::printEvent() const {
    cout << "ID: " << ID << endl;
    cout << "name: " << name << endl;
    cout << "level: " << level << endl;
    cout << "coords: " << coordinates.x << ", " << coordinates.y << endl;
    cout << "radius: " << radius << endl;
    for (int i = 0; i < (int)actions.size(); i++) {
        actions[i].printAction();
        cout << endl;
    }
} */