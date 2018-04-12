#ifndef EVENT
#define EVENT

#include "base.h"

class EventFactory;

class Event : public Item, public Located {
public:
    void runEvent();
    /* test function: */
    void printEvData();

    friend EventFactory;
private:
    Event() = default;
    Event(str, str, short, coord, short);
    short radius;
    std::vector<Action> eventActions;
};

class EventFactory : public IFactory {
public:
    Event* create();
};

#endif  // EVENT