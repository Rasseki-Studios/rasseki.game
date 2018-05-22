#ifndef SESSIONDATA
#define SESSIONDATA

#include "items_data.h"

// #include "items_data.h"
/* 
class Hero ;
class SystemData;
class GameData;
class SurfaceData;
class EventsData;
class ArtifactsData;
struct coord;
 */
namespace SessionData {
    extern SurfaceData surfaceData;
    extern GameData gameData;
    extern SystemData systemData;
    extern ArtifactsData artifactsData;
    // extern CreatureData creatureData;
    extern EventsData eventsData;
    // hero initialization
    extern Hero hero;
    extern str message;
}

#endif // SESSIONDATA