#ifndef EVENT
#define EVENT

#include "item.h"
#include "location.h"

class Action {
public:
    void run() const;
    /* DEBUG_FUNCTION */ void printAction();
private:
    str subjectID;  // Item *subject in future
    str command;  // Converts to function in run()
    str objectID;  // Item *object in future
    str diaryNote;
    str condition;
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
    // Event() = default;
    Event(str, str, short, coord, short, std::vector<Action>);
    short radius;
    std::vector<Action> actions;
};

class EventFactory : public ItemFactory {
public:
    Event* createFromJson(str filename);
    // getFromJson(str filename);
};

#endif  // EVENT