#include "Things.h"

Artifact::Artifact(std::string name, std::string id, short level, short power) : Item(name, id, level) {
    this->power = power;
}

short Artifact::GetPower() const {
    return power;
}