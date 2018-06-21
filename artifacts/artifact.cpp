/* by stanford */

#include "artifact.h"

Artifact::Artifact(str id, str name, short level, str type, short power)
: Item(id, name, level), type(type), power(power) {}

str Artifact::GetType() const {
    return type;
}

short Artifact::ApplyModifier() const {
    return power;
}
