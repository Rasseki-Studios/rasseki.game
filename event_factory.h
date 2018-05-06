#ifndef EVENT_FACTORY
#define EVENT_FACTORY

#include <vector>

#include "location.h"
#include "event.h"

struct ActionData : public ItemData {
    str subjectID, command, objectID, diaryNote, condition;
    short duration;
    void set(str, str, str, str, str, short);
    /* DEBUG */ void PrintActionData();
};

struct EventData : public ItemData {
    str ID, name;
    coord coordinate;
    short radius, level;
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