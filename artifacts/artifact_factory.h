/* by stanford */

#ifndef ARTIFACT_FACTORY
#define ARTIFACT_FACTORY

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>

#include "artifact.h"


using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::unordered_map;
using std::unordered_set;

struct ArtifactData : public ItemData {
    str type;
    short power;
    bool isValid();
    void set(str, str, short, str, short);
};

class ArtifactParser {
public:
    virtual shared_ptr<vector<ArtifactData>> getData(str filename);
    // By default it parses json.
    // But we can inherit another class from this
    // and override this method to parse any other file type.
};

class ArtifactFactory {
public:
    int InitAll(str folder, unordered_map<str, Artifact>&);
private:
    ArtifactParser parser;
    shared_ptr<vector<ArtifactData>> tempData;
    // needs when there are several artifacts in one file

    Artifact& Create(ArtifactData&);
};

#endif //ARTIFACT_FACTORY
