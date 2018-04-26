#ifndef EVENT
#define EVENT

#include "item.h"
#include "location.h"
#include "subjects.h"

class EventFactory;  // forward declaration
class Action {
public:
    void run() const;
    /* DEBUG_FUNCTION */ void printAction();
    friend EventFactory;
private:
    Action(Creature*, str, Item*, str, str, short, short);
    Creature *subject;
    str command;  // Converts to function in run()
    Item *object;
    str diaryNote;
    str condition;  // Converts to if { ... } in run()
    short priority;
    short duration;
};

class Event : public Item, public Located {
public:
    void runEvent();
    /* DEBUG_FUNCTION */ void printEvent();
    friend EventFactory;
private:
    Event(str, str, short, coord, short, std::vector<Action>);
    short radius, priority;
    std::vector<Action> actions;
};

#endif  // EVENT