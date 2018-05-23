#include "session_data.h"
#include <iostream>

namespace SessionData {
    SystemData systemData;
    GameData gameData;
    SurfaceData surfaceData;
    EventsData eventsData;
    ArtifactsData artifactsData;

    str diaryString;
    str writer;

    // hero initialization
    std::string name = "Moleque";
    std::string id = "super_hero";
    coord start(200, 200);
    Hero hero(id, name, 1, 10, start);
}

