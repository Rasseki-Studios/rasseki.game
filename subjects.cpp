#include "subjects.h"

//---ARTIFACT---
Artifact::Artifact(std::string name, std::string id, short level, short power) : Item(name, id, level) {
    this->power = power;
}

short Artifact::GetPower() const {
    return power;
}


//---STORAGE---
Storage::Storage(short count) {
    artifacts.reserve(count);   //выделение памяти под count этементов
}

void Storage::AddArtifact(Artifact new_artifact) {  //добавить проверку на размер емкости
    artifacts.insert(artifacts.end(), new_artifact);
}

void Storage::RemoveArtifact(std::string id) {
    for (std::vector<Artifact>::iterator it = artifacts.begin(); it != artifacts.end(); it++) {
        if ((*it).GetId() == id) {
            artifacts.erase(it);
        }
    }
}

Artifact* Storage::GetArtifact(std::string id) {
    for (std::vector<Artifact>::iterator it = artifacts.begin(); it != artifacts.end(); it++) {
        if ((*it).GetId() == id) {
            return it.base();
        }
    }
    return nullptr;
}


//---CREATURE---
Creature::Creature(std::string name, std::string id, short level, short speed, coord coordinates) : Item(name, id, level), Movable(coordinates, speed) {}


//---HERO---
Hero::Hero(std::string name, std::string id, short level, short speed, coord coordinates, Storage *inventary) : Creature(name, id, level, speed, coordinates) {
    this->inventary = inventary;
}

Storage* Hero::GetInventary() const {
    return inventary;
}