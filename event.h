#ifndef EVENT
#define EVENT

#include "base.h"
#include "libs/json_fwd.hpp"

using json = nlohmann::json;

class Action {
public:
    void run() const;
    /* DEBUG_FUNCTION */ void printActData();
private:
    str subjectID;  // Item *subject in future
    str command;  // Converts in function in run()
    str objectID;  // Item *object in future
    str diaryNote;
    short duration;
    void set(str, str, str, str, short);
    friend void from_json(const json&, Action&);
};

class EventFactory;

class Event : public Item, public Located {
public:
    void runEvent();
    /* DEBUG_FUNCTION */ void printEvData();
    friend EventFactory;
private:
    Event() = default;
    Event(str, str, short, coord, short, std::vector<Action>);
    short radius;
    std::vector<Action> actions;
};

class EventFactory : public IFactory {
public:
    Event* create();
};

#endif  // EVENT