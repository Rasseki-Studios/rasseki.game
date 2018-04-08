#include "subjects.h"

//---ARTIFACT---
Artifact::Artifact(string name, short level, short power) {
    this->name = name;
    this->level = level;
    this->power = power;
}

//---STORAGE---
Storage::Storage(short count) {
    artifacts.reserve(count);   //выделение памяти под count этементов
}

void Storage::AddArtifact(Artifact new_artifact) {  //добавить проверку на размер емкости
    artifacts.insert(artifacts.end(), new_artifact);
}

void Storage::RemoveArtifact(short id) {
    for (int i = 0; i < artifacts.size(); i++) {
        if (artifacts[i].id == id) {
            artifacts.erase(artifacts.begin() + i);
        }
    }
}

Artifact Storage::GetArtifact(short id) {
    for (int i = 0; i < artifacts.size(); i++) {
        if (artifacts[i].id == id) {
            return artifacts[i];
        }
    }
    return NULL;
}

//---CREATURE---
Creature::Creature(string name, short level, short speed, coord coordinates) {
    this->name = name;
    this->level = level;
    this->speed = speed;
    this->coordinates = coordinates;
}

//---HERO---
Hero::Hero(string name, short level, short speed, coord coordinates, Storage inventary) : Creature(name, level, speed, coordinates) {
    this->inventary = inventary;
}