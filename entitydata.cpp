#include "entitydata.h"
#include <iostream>

std::unordered_map<std::string, Creature> EntityData::creaturesList;
std::unordered_map<std::string, Artifact> EntityData::artifactsList;


void EntityData::add(Creature creature) {
    creaturesList.insert(make_pair(creature.GetId(), creature));
}

void EntityData::add(Artifact artifact) {
    artifactsList.insert(make_pair(artifact.GetId(), artifact));
}

bool EntityData::checkCreature(std::string id) {
    return creaturesList.count(id);
}

bool EntityData::checkArtifact(std::string id) {
    return artifactsList.count(id);
}

void EntityData::printAllCreatures() {
    std::unordered_map<std::string, Creature>::iterator it = creaturesList.begin(); 
    for (auto it : creaturesList) 
        std::cout << it.first << std::endl;
}

void EntityData::printAllArtifacts() {
    std::unordered_map<std::string, Artifact>::iterator it = artifactsList.begin(); 
    for (auto it : artifactsList) 
        std::cout << it.first << std::endl;
}