#ifndef ITEMSDATA
#define ITEMSDATA

#include <string>
#include <unordered_map>

#include "hero.h"
#include "event_factory.h"
#include "artifact.h"
#include "surface.h"    
#include "matrix.hpp"

class SystemData {
public:
    SystemData(str nextLocationName = "default_location");
    str resourcesDirectory; // directory with all the resources
    str nextLocationName; // ID of a map going to be loaded
    str currentLocationName; // ID of a map loaded
    str mapName; // name of the .bmp file
};

class GameData {
// stores finished events and other stuff
public:
    int mapHeight;
    int mapWidth;
    str diaryString; // what we are writin'
    str writer;  // who is writin'
};

class EventsData {
public:
    EventsData();
    ~EventsData();
    Event* getEvent(const str);
    Event* getEvent(Coord);
    bool EventExists(str);
    void RemoveFrontEvent(Coord);
    // more methods coming in future
private:
    void PulverizeEvents(std::unordered_map<str, Event>&); //pulverizes events from eventList
    Matrix<std::vector<str>*> eventMatrix;
    std::unordered_map<str, Event> currentEventList;
    // std::unordered_map<str, Event> globalEventList;
};

class ArtifactsData {
public:
    ArtifactsData();
    bool ArtifactExists(str);
    Artifact* getArtifact(const str);
private:
    std::unordered_map<str, Artifact> currentArtifactsList;
    // std::unordered_map<str, Artifact> globalArtifactsList;
};

#endif 