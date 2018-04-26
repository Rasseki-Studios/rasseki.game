#ifndef PARSER
#define PARSER

#include <string>

#include "event_factory.h"

using str = std::string;

class Parser {
public:
    static eventData* getEventData(str filename);
};

#endif  // PARSER