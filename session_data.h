#ifndef SESSION
#define SESSION

#include <string>
#include <unordered_map>

#include "item.h"
#include "units.h"
#include "things.h"
#include "event.h"
#include "mapdata.h"

class LocationData { 
public:
      LocationData(str); //here goes location name (e.g. bmp filename)
      ~LocationData();
      bool EnterLocation(str);
      SurfaceMapData surfMap;
      EventsMapData evMap;
private:
      str ID = NULL;
};

class GameData {
public:
      friend ItemFactory;
      GameData(str locationName) : currentLocation(locationName) { };
      ~GameData();
      LocationData currentLocation;
private:
      static std::unordered_map<str, Artifact> artifactsList;
      static std::unordered_map<str, Creature> creaturesList;
      static std::unordered_map<str, Event> eventsList;
};


//singleton class
class SessionData {
public:
    static SessionData& getInstance();
    SessionData(SessionData const&) = delete;      //disable copy
    void operator=(SessionData const&) = delete;   //disable copy

    GameData gameData(str locationName);
private:
    SessionData() { };       // forbid to create instance outside
    ~SessionData() { };      // forbid to delete instance outside    
};

#endif //SESSION

//smth that can be useful sometime...
/*    
      static bool checkArtifact(str);
      static bool checkCreature(str);
      static bool checkEvent(str);
      static void add(Artifact);
      static void add(Creature);
      static void add(Event);
      static void printAllArtifacts();
      static void printAllCreatures();
      static void printAllEvents(); 
*/