#ifndef ITEMSDATA
#define ITEMSDATA

#include <string>
#include <experimental/filesystem>
#include <unordered_map>
#include <memory>

#include "hero.h"
#include "event_factory.h"
#include "artifact.h"
#include "surface.h"
#include "matrix.hpp"
// #include "session_data.h"
#include "paths.h"

namespace fs = std::experimental::filesystem;

class SystemData {
public:
    SystemData(str nextLocationName = defaultLocation);
    fs::path resourcesPath;
    fs::path artifactsPath;
    fs::path eventsPath;
    fs::path mapPath;

    str nextLocationName; // ID of a map going to be loaded
    str currentLocationName; // ID of a map loaded
};

class GameData {
// stores finished events and other stuff
public:
    int mapHeight;
    int mapWidth;
    void WriteToDiary(str);
    str diaryString; // what we are writin'
    str writer;  // who is writin'
    bool changeInventory = true;
    bool tdWorking = false;
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
    std::shared_ptr<Artifact> getArtifact(const str);
private:
    std::unordered_map<str, Artifact> currentArtifactsList;
    // std::unordered_map<str, Artifact> globalArtifactsList;
};

#endif 
