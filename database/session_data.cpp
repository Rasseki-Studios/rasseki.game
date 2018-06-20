#include "session_data.h"
#include <iostream>

namespace SessionData {
    SystemData systemData;
    SurfaceData surfaceData;
    GameData gameData;
    ArtifactsData artifactsData;
    EventsData eventsData;

    // hero initialization
    // temporarily solution
    std::string name = "Moleque";
    std::string id = "super_hero";
    Coord start(651, 414);
    Hero hero(id, name, 1, 10, start);
}