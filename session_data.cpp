#include "session_data.h"
#include <iostream>

namespace SessionData {
    SystemData systemData;
    GameData gameData;
    SurfaceData surfaceData;
    EventsData eventsData;
    ArtifactsData artifactsData;

    // hero initialization
    std::string name = "Hero";
    std::string id = "super_hero";
    //coord start(200, 200);
    Hero hero(name, id, 1, 10, {200, 200});
}

