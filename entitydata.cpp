#include "entitydata.h"

std::unordered_map<std::string, Creature> EntityData::creaturesList;
std::unordered_map<std::string, Artifact> EntityData::artifactsList;


void EntityData::add(Creature creature) {
    creaturesList.insert(make_pair(creature.GetId(), creature));
}

void EntityData::add(Artifact artifact) {
    artifactsList.insert(make_pair(artifact.GetId(), artifact));
}
