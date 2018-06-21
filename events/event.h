/* by stanford */

#ifndef EVENT
#define EVENT

#include "item.h"
#include "located.h"
#include "action.h"

#include <vector>
using std::vector;

#include <memory>
using std::unique_ptr;
using std::move;

class EventFactory;  // forward declaration
class Event : public Item, public virtual Located {
public:
    short getRadius() const;
    short getPriority() const;
    void Run() const;
    friend EventFactory;
private:
    Event(str, str, short, Coord, short, short, vector<unique_ptr<Action>>&);
    short radius, priority;
    vector<unique_ptr<Action>> actions;
};

#endif  // EVENT