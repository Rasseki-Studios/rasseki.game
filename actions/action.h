/* by stanford */

#ifndef ACTIONS
#define ACTIONS

#include <string>
using str = std::string;

#include "matrix.hpp"


class Action {
public:
    void Run() const;
    Action(int chance, str sNote, str fNote, int dur);
private:
    virtual void MakeAction() const = 0;
    virtual bool CheckCondition() const;

    bool ThrowDice() const;  // decides, if action may be run, using chance
    int chance;  // percents, 0 - 100
    void PrintToDiary(const bool success = true) const;
    str successNote;
    str failureNote;
    short duration;
};


/* ***************************** ACTION TYPES *************************** */

class ActionFactory;  // forward declaration

class GiveArtifact : public Action {
    friend ActionFactory;
private:
    str artifactID;
    GiveArtifact(int chance, str sNote, str fNote, int dur, str artID);
    void MakeAction() const;
};

class TakeAwayArtifact : public Action {
    friend ActionFactory;
private:
    str artifactID;
    TakeAwayArtifact(int chance, str sNote, str fNote, int dur, str artID);
    void MakeAction() const;
};

class Teleport : public Action {
    friend ActionFactory;
private:
    Coord destination;
    Teleport(int chance, str sNote, str fNote, int dur, Coord dest);
    void MakeAction() const;
};

class Wait : public Action {
    friend ActionFactory;
private:
    Wait(int chance, str sNote, str fNote, int dur);
    void MakeAction() const;
};


// prepared for better times, when creatures will be added
/* class BeginFight : public Action {
    friend ActionFactory;
private:
    BeginFight(int chance, str sNote, str fNote, int dur, str enemyID);
    str enemyID;
    void MakeAction() const;
};

class Fight : public Action {
    friend ActionFactory;
private:
    BeginFight(int chance, str sNote, str fNote, int dur, str enemyID);
    str enemyID;
    void MakeAction() const;
}; */

#endif  // ACTIONS