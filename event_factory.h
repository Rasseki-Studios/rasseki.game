#ifndef FACTORY
#define FACTORY

#include <vector>

#include "location.h"
#include "event.h"

class EventFactory : public ItemFactory {
public:
    int initEventMap(str folder);
    Event* createFromJson(str filename);
};

// unfortunately we can't use std::map instead of
// structures because of different collected types
struct actionData {
    str subjectID, command, objectID, diaryNote, condition;
    short duration;
    void set(str, str, str, str, str, short);
    /* DEBUG */ void printActionData();
};

struct eventData {
    str ID, name;
    coord coordinate;
    short radius, level;
    std::vector<actionData> actions;
    eventData(str, str, coord, short, short, std::vector<actionData>);
    /* DEBUG */ void printEventData();
};

// instead of class "json-event-parser" with only one static method:
eventData* getEventData(str filename);
// this function can be defined anywhere and however we want (json/xml/rss/...)
// now it is definied in event_parser.cpp

#endif

//селиванов