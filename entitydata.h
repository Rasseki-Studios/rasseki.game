#include "item.h"
#include "subjects.h"

#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef UNORDERED_MAP
#define UNORDERED_MAP
#include <unordered_map>
#endif

class EntityData {
public:
    static bool checkCreature(std::string);
    static bool checkArtifact(std::string);
    static void add(Creature);
    static void add(Artifact);
    static void printAllCreatures();
    static void printAllArtifacts();
private:
    static std::unordered_map<std::string, Creature> creaturesList;
    static std::unordered_map<std::string, Artifact> artifactsList;
};