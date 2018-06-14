/* by stanford */

#ifndef ARTIFACT
#define ARTIFACT

#include "item.h"

// System of artifact modifiers will be strongly expanded
//                 ...sometimes...
class ArtifactFactory;  //forward declaration
class Artifact : public Item {
public:
    Artifact(str, str, short, str, short);
    str GetType() const;
    short ApplyModifier() const;
private:
    str type;
    short power;
};

#endif //ARTIFACT
