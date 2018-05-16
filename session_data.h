#ifndef SESSION
#define SESSION

#include <string>
#include <unordered_map>

#include "units.h"
#include "things.h"
#include "event_factory.h"
#include "artifact.h"
// #include "artifact_factory.h"
#include "mapdata.h"
#include "mapscanner.h"
#include "surface.h"


class SystemData {
    // coming soon
};

class GameData {
// stores finished events and other stuff
public:
//    bool Init();
    static short getHeight();
    static short getWidth();
    static void setHeight(short);
    static void setWidth(short);
private:
    static short mapHeight;
    static short mapWidth;    
};

class EventsData {
public:
    bool Init();
    Event& getEvent(const str);
    Event& getEvent(coord);
    // more methods coming in future
private:
    void SortEventVector(std::vector<Event>*);
    void PulverizeEvents(std::unordered_map<str, Event>&); //pulverizes events from eventList
    std::vector<Event> ***eventMatrix;
    // std::unique_ptr<Event[][]> eventMatrix;
    std::unordered_map<str, Event> currentEventList;
    // std::unordered_map<str, Event> globalEventList;

};

class ArtifactsData {
public:
    bool Init();
    Artifact& getArtifact(const str);
private:
    std::unordered_map<str, Artifact> currentArtifactsList;
    std::unordered_map<str, Artifact> globalArtifactsList;

};

#endif //SESSION