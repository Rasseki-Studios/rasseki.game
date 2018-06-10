/*  by stanford */

#include "artifact.h"

Artifact::Artifact(str id, str name, short level, str type, short power)
: Item(id, name, level), type(type), power(power) {}

str Artifact::GetType() const {
    return type;
}

short Artifact::ApplyModifier() const {
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
