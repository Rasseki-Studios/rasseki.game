/* by stanford */

#ifndef EVENT_FACTORY
#define EVENT_FACTORY

#include <vector>
#include <memory>
#include <unordered_set>
#include <unordered_map>

#include "event.h"
#include "action_factory.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::unordered_set;
using std::unordered_map;

struct EventData : public ItemData {
    Coord coordinate;
    short radius, priority;
    std::vector<ActionData> actions;
    bool isValid();
    void set(str, str, short, Coord, short, short, std::vector<ActionData>);
};

class EventParser {
public:
    virtual shared_ptr<vector<EventData>> getData(str filename);
    // By default it parses json.
    // But we can inherit another class from this
    // and override this method to parse any other file type.
};

class EventFactory {
public:
    int InitAll(str folder, unordered_map<str, Event>&);
private:
    EventParser eventParser;
    ActionFactory actionFactory;
    shared_ptr<vector<EventData>> tempData;
    // needs when there are several events in one file

    Event& Create(EventData&);
};

#endif