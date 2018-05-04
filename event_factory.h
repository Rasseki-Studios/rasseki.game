#ifndef EVENT_FACTORY
#define EVENT_FACTORY

#include <vector>

#include "location.h"
#include "event.h"

class EventFactory : public ItemFactory {
public:
    int InitAll(str folder);
    Event* CreateOne(str filename);
};

// unfortunately we can't use std::map instead of
// structures because of different collected types
struct ActionData {
    str subjectID, command, objectID, diaryNote, condition;
    short duration;
    void set(str, str, str, str, str, short);
    /* DEBUG */ void PrintActionData();
};

struct EventData {
    str ID, name;
    coord coordinate;
    short radius, level;
    std::vector<ActionData> actions;
    EventData(str, str, coord, short, short, std::vector<ActionData>);
    /* DEBUG */ void PrintEventData();
};

// instead of class "json-event-parser" with only one static method:
EventData* getEventData(str filename);
// this function can be defined anywhere and however we want (json/xml/rss/...)
// now it is definied in event_parser.cpp

#endif

//селиванов