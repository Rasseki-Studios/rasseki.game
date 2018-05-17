#ifndef EVENT
#define EVENT

#include "item.h"
#include "location.h"

#include <vector>

class EventFactory;  // forward declaration
class Action {
public:
    void run() const;
    /* DEBUG_FUNCTION */ void printAction();
    friend EventFactory;
private:
    Action(/* Item*,  */str, str, str, str, short);
    // Item *subject;
    str command;  // Converts to function in run()
    str objectID;
    str diaryNote;
    str condition;  // Converts to if { ... } in run()
    short duration;
};

class Event : public Item, public virtual Located {
public:
    short getRadius();
    short getPriority();
    void runEvent() const;
    /* DEBUG_FUNCTION */ void printEvent() const;
    friend EventFactory;
private:
    Event(str, str, short, coord, short, short, std::vector<Action>);
    short radius, priority;
    std::vector<Action> actions;
};

#endif  // EVENT