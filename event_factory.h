#ifndef EVENT_FACTORY
#define EVENT_FACTORY

#include <vector>
#include <memory>
#include <unordered_set>

#include "location.h"
#include "event.h"

#include "session_data.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::unordered_set;

struct ActionData {
    // Action is not an Item and has no own factory or parser
    str subjectID, command, objectID, diaryNote, condition;
    short duration;
    void set(str, str, str, str, str, short);
    /* DEBUG */ void PrintActionData();
};

struct EventData : public ItemData {
    coord coordinate;
    short radius;
    std::vector<ActionData> actions;
    void set(str, str, coord, short, short, std::vector<ActionData>);
    /* DEBUG */ void PrintEventData();
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
    // EventFactory();
    int InitAll(str folder, unordered_map<str, Event>&);
private:
    EventParser parser;
    shared_ptr<vector<EventData>> tempData;
    // needs when there are several artifacts in one file

    bool isValid(EventData&);
    Event* Create(EventData&);
    unordered_set<str> commandList {
        "give",         // give artifact
        "take_away",    // remove artifact
        "wait",         // nothing
        "fight",        // fight
        "die"           // respawn
    };
    unordered_set<str> conditionList {
        "",             // no condition
        "win",          // win fight
        "lose"          // lose fight
    };
};

#endif