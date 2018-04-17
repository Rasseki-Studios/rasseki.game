#ifndef PARSER
#define PARSER

#ifndef STRING
#define STRING
#include <string>
#endif

#include "location.h"

using str = std::string;

// unfortunately we can't use std::map instead of 
// structures because of different collected types
struct actionData {
    str subjectID, command, objectID, diaryNote, condition;
    short duration;
    void set(str, str, str, str, str, short);
    void printActionData();
};

struct eventData {
    str ID, name;
    coord coordinate;
    short radius, level;
    std::vector<actionData> actions;
    eventData(str, str, coord, short, short, std::vector<actionData>);
    void printEventData();
};

class Parser {
public:
    static eventData* getEventData(str filename);
};

#endif  // PARSER