#ifndef EVENT_FACTORY
#define EVENT_FACTORY

#include <vector>

#include "location.h"
#include "event.h"

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
    EventData(str, str, coord, short, short, std::vector<ActionData>);
    /* DEBUG */ void PrintEventData();
};

class EventParser : public ItemParser {
public:
    EventData* getData(str filename);
};

class EventFactory : public ItemFactory {
public:
    int InitAll(str folder);
    Event* Create(str filename);
private:
    EventParser parser;
};

#endif