#ifndef EVENT
#define EVENT

#include "item.h"
#include "location.h"
#include "subjects.h"

class Action {
public:
    void run() const;
    /* DEBUG_FUNCTION */ void printAction();
private:
    Creature *subject;
    str command;  // Converts to function in run()
    Item *object;
    str diaryNote;
    str condition;  // Converts to if { ... } in run()
    short duration;
    void set(str, str, str, str, str, short);
};

class EventFactory;  // forward declaration
class Event : public Item, public Located {
public:
    void runEvent();
    /* DEBUG_FUNCTION */ void printEvent();
    friend EventFactory;
private:
    Event(str, str, short, coord, short, std::vector<Action>);
    short radius;
    std::vector<Action> actions;
};

class EventFactory : public ItemFactory {
public:
    int initEventMap(str path);
    Event* createFromJson(str filename);
};

#endif  // EVENT