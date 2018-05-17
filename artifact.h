#ifndef ARTIFACT
#define ARTIFACT

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>

#include "item.h"

using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::shared_ptr;
using std::make_shared;

// System of artifact modifiers will be strongly expanded
//                 ...sometimes...
class Artifact : public Item {
public:
    Artifact(str, str, short, str, short);
    str getID() const;
    short GetPower() const;
private:
    // some kind of effect description
    // effect can be applied with function GetPower()
    str type;
    short power;
};

struct ArtifactData : public ItemData {
    // has the same fields as Artifact,
    // but values are not validated by factory
    str type;
    short power;
    void set(str, str, short, str, short);
    /* DEBUG */ void PrintArtifactData();
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

    bool isValid(ArtifactData&);
    Artifact* Create(ArtifactData&);

    unordered_set<str> typeList {
        "weapon",
        "speed_booster",
        "throw_weapon"
    };
};

class Storage {
public:
    Storage(short);
    void AddArtifact(Artifact);
    void RemoveArtifact(str);
    Artifact* GetArtifact(str);
private:
    std::vector<Artifact> artifacts;
};

#endif //ARTIFACT
