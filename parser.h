#ifndef PARSER
#define PARSER

#include <string>

#include "event_factory.h"

using str = std::string;

class EventParser {
public:
    static eventData* getEventData(str filename);
};

class CreatureParser {
    static creatureData* getCreatureData(str filename);
};

class ArtifactParser {
    static artifactData* getArtifactData(str filename);
};

#endif  // PARSER