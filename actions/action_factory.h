/* by stanford */

#ifndef ACTION_FACTORY
#define ACTION_FACTORY

#include <unordered_map>
using std::unordered_map;

#include <memory>
using std::move;
using std::unique_ptr;

#include "action.h"

struct ActionData {

    // common values
    str type;
    int chance;
    str successNote, failureNote;
    int duration;

    // for artifact-using actions
    str artifactID;

    // for coord-using actions
    Coord coord;

    bool isValid();
};

class ActionFactory {
public:
    unique_ptr<Action> Create(ActionData &actionData);
};

#endif  // ACTION_FACTORY