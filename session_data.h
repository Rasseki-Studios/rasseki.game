#ifndef SESSION
#define SESSION

#include <string>
#include <unordered_map>

#include "units.h"
#include "things.h"
#include "event_factory.h"
#include "artifact.h"
// #include "artifact_factory.h"
#include "surface.h" //here is SurfaceData, temporary solution.

class SystemData {
    // coming soon
};

class GameData {
// stores finished events and other stuff
public:
    bool Init(); 
    int mapHeight;
    int mapWidth;
    str locationID; // ID of a map going to be loaded
};

class SurfaceData {
public:
    bool Init();
    int getWidth();
    int getHeight();
    bool RadiusIsValid(coord&, short);
    bool IsWalkable(coord&);
    short getSurface(coord&);
    Surface& getSurface(str);   
private:
    bool CoordIsValid(coord&);
    int mapWidth, mapHeight;
    short** surfaceMatrix;    
    // std::unordered_map<str, Surface> currentSurfaceList; // currently useless
    // std::unordered_map<str, Surface> globalSurfaceList; //will be added in future
};

class EventsData {
public:
    bool Init();
    Event& getEvent(const str);
    Event& getEvent(coord);
    void removeFrontEvent(coord); // no realization yet
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
    // std::unordered_map<str, Artifact> globalArtifactsList;
};

namespace SessionData {
    SystemData systemData;
    GameData gameData;
    SurfaceData surfaceData;
    EventsData eventsData;
    ArtifactsData artifactsData;

    // hero initialization
    str name = "Hero";
    str id = "super_hero";
    coord start;
    Hero hero(name, id, 1, 10, start, nullptr);
}

#endif //SESSION