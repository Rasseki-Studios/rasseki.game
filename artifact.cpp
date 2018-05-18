#include "artifact.h"

Artifact::Artifact(std::string id, std::string name, short level, std::string type, short power) : Item(id, name, level), type(type), power(power) {}

std::string Artifact::GetType() const {
    return type;
}

short Artifact::GetPower() const {
    return power;
}