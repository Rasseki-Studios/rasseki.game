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

/*    
class LocationData { 
public:
    LocationData(str); //here goes location name (e.g. bmp filename)
    ~LocationData();
    bool EnterLocation(str);
    SurfacepData surfMap;
    EventsData evMap;
private:
    // str ID = NULL;
};
*/

/*
class CurrentLocation {
    public:
        bool Init();
        CurrentLocation();
        ~CurrentLocation();
    private:
        int mapHeight; 
        int mapWidth;
        short** surfaceMatrix;
        std::vector<Event> ***eventMatrix;

        std::unordered_map<str, Event> eventsList;
        std::unordered_map<str, Artifact> artifactsList;
        // std::unordered_map<str, Creature> creaturesList;
    
    };

    class GlobalLocation {
    public:
        bool Init();
    
    private:
        
    };

class GameData {
public:
    friend ItemFactory;
    GameData(str locationName) : currentLocation(locationName) { };
    ~GameData();
    CurrentLocation currentLocation;

    bool checkEvent(str);
    bool checkArtifact(str);
    // bool checkCreature(str);
    void add(Event);
    void add(Artifact);
    // void add(Creature);
    void printAllEvents(); 
    void printAllArtifacts();
    // void printAllCreatures();
private:
    std::unordered_map<str, Event> eventsList;
    std::unordered_map<str, Artifact> artifactsList;
    // std::unordered_map<str, Creature> creaturesList;
};


//singleton class
class SessionData {
public:
    SessionData& getInstance();
    SessionData(SessionData const&) = delete;      //disable copy
    void operator=(SessionData const&) = delete;   //disable copy

    GameData gameData(str locationName);
private:
    SessionData() { };       // forbid to create instance outside
    ~SessionData() { };      // forbid to delete instance outside    
};

/*
//smth that can be useful sometime...
        bool checkArtifact(str);
        bool checkCreature(str);
        bool checkEvent(str);
        void add(Artifact);
        void add(Creature);
        void add(Event);
        void printAllArtifacts();
        void printAllCreatures();
        void printAllEvents(); 
*/

class SystemData {
    // coming soon
};

class GameData {
// stores Hero, finished events and other stuff
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

class SurfaceData {
public:
    bool Init(const str);
    int getWidth();
    int getHeight();
    bool **GetMiniMap(); // coming soon
    short getSurface(coord);
    Surface& getSurface(str);   

private:
    int mapWidth, mapHeight;
    short** surfaceMatrix;
    std::unordered_map<str, Surface> currentSurfaceList; // currently useless
    // std::unordered_map<str, Surface> globalSurfaceList; //will be added in future

};

class EventsData {
public:
    bool Init();
    Event& getEvent(const str);
    Event& getEvent(coord);

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
// */

/* 
класс локейшн наследуем от айтема
ивенты, карты и артефакты мы выносим в отдельные классы, где находится вся их логика.
они должны быть самодостаточны.
в каждом нужно держать еще и фабрику и делать инитОл
 


*/