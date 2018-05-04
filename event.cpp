#include "event.h"

//for error printing, should be changed to QT error printer
#include <iostream>
using std::cout;
using std::endl;

Action::Action(Creature *subj, str _command, Item *obj,
    str _note, str _cond, short _duration) : 
    subject(subj),
    command(_command),
    object(obj),
    diaryNote(_note),
    condition(_cond),
    duration(_duration) {
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

Event::Event(str _ID, str _name, short _level, coord _coord,
    short _priority, short _radius, std::vector<Action> _actions) :
    Item(_ID, _name, _level),
    Located(_coord),
    priority(_priority),
    radius(_radius),
    actions(_actions) {
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