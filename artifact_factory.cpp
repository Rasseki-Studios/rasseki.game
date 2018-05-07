#ifndef ARTIFACT_FACTORY
#define ARTIFACT_FACTORY

#include "things.h"

class ArtifactFactory : public ItemFactory {
public:
    int InitAll(str folder);
    Artifact* CreateOne(str filename);
};

#endif  // ARTIFACT_FACTORY