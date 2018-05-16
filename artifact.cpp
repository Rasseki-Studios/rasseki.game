#include "artifact.h"

Artifact::Artifact(
    str _ID, str _name, short _level,
    str _type, short _power)
    :
    Item(_ID, _name, _level),
    type(_type), power(_power) {
}

void ArtifactData::set(
    str _ID, str _name, short _level,
    str _type, short _power) {

    ID= _ID;
    name = _name;
    level = _level;
    type = _type;
    power = _power;
}