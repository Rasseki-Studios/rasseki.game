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
    static bool check(Creature&);
    static bool check(Artifact&);
    static void add(Creature);
    static void add(Artifact);
    static void printAllCreatures();
    static void printAllArtifacts();
private:
    static std::unordered_map<std::string, Creature> creaturesList;
    static std::unordered_map<std::string, Artifact> artifactsList;
    

}