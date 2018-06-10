#ifndef EVENT
#define EVENT

#include "item.h"
#include "location.h"
#include "action.h"

#include <vector>

class EventFactory;  // forward declaration
class Event : public Item, public virtual Located {
public:
    short getRadius();
    short getPriority();
    void Run() const;
    friend EventFactory;
private:
    Event(str, str, short, Coord, short, short, std::vector<Action*>);
    short radius, priority;
    std::vector<Action*> actions;
};

#endif  // EVENT