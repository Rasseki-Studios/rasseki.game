#include "artifact.h"

Artifact::Artifact(std::string id, std::string name, short level, std::string type, short power) : Item(id, name, level), type(type), power(power) {}

std::string Artifact::GetType() const {
    return type;
}

short Artifact::GetPower() const {
    return power;
}

void ArtifactData::set(
    str _ID, str _name, short _level,
    str _type, short _power) {

    ID = _ID;
    name = _name;
    level = _level;
    type = _type;
    power = _power;
}
