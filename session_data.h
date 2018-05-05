#ifndef SESSION
#define SESSION

#include "item.h"
#include "subjects.h"
#include "event.h"
#include "mapdata.h"
#include <string>
#include <unordered_map>

class LocationData { 
public:
      LocationData(std::string); //here goes location name (e.g. bmp filename)
      ~LocationData();
      bool EnterLocation(std::string);
      SurfaceMapData surfMap;
      EventsMapData evMap;
private:
      std::string ID = NULL;
};

class GameData {
public:
      friend ItemFactory;
      GameData(std::string locationName) : currentLocation(locationName) { };
      ~GameData();
      LocationData currentLocation;
private:
      static std::unordered_map<std::string, Artifact> artifactsList;
      static std::unordered_map<std::string, Creature> creaturesList;
      static std::unordered_map<std::string, Event> eventsList;
};


//singleton class
class SessionData {
public:
    static SessionData& getInstance();
    SessionData(SessionData const&) = delete;      //disable copy
    void operator=(SessionData const&) = delete;   //disable copy

    GameData gameData(std::string locationName);
private:
    SessionData() { };       // forbid to create instance outside
    ~SessionData() { };      // forbid to delete instance outside    
};

#endif //SESSION

//smth that can be useful sometime...
/*    
      static bool checkArtifact(std::string);
      static bool checkCreature(std::string);
      static bool checkEvent(std::string);
      static void add(Artifact);
      static void add(Creature);
      static void add(Event);
      static void printAllArtifacts();
      static void printAllCreatures();
      static void printAllEvents(); 
*/