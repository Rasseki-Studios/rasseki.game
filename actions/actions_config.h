/* by stanford */

#ifndef ACTIONS_CONFIG
#define ACTIONS_CONFIG

#include <unordered_set>
#include <string>

const int MIN_CHANCE_PERCENT = 0;
const int MAX_CHANCE_PERCENT = 100;

const int MAX_ACTION_DURATION = 30;  // in seconds
const int MIN_ACTION_DURATION = 2;   // in seconds


/* IMPORTANT!!! */
/* ACTIONS ACCELERATED 10 TIMES! */
/* CHANGE TO 1000 FOR PRODUCTION (kek) */
const int DURATION_FACTOR = 100;

const std::unordered_set<std::string> actionList {
    "give",
    "take_away",
    "wait",
    "teleport"

    // prepared for better times, when creatures will be added

    // "begin_fight",
    // "fight"
};

#endif  // ACTIONS_CONFIG