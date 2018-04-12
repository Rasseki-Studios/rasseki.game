#ifndef EVENT
#define EVENT

#include "base.h"

class Event : public Item, public Located {
public:
    void runEvent();
private:
    std::vector<Action> eventActions;
};

class EventFactory : public IFactory {
public:
    Event* create();
// private:

};

#endif  // EVENT