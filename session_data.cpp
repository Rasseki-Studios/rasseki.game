#include "session_data.h"
#include "mapdata.h"

bool LocationData::EnterLocation(std::string name) {
    if (!ID.empty()) {
        surfMap.~SurfaceMapData();
        evMap.~EventsMapData();
    };
    //here we need to add events on the evMap
    bool surfMapSuccess = surfMap.InitMatrix(name);
    bool evMapSuccess = evMap.InitMatrix();
    return surfMapSuccess && evMapSuccess;

}

LocationData::LocationData(std::string locationName) {
    // ID = locationName;
    if (EnterLocation(ID)) ID = locationName;
}

SessionData& SessionData::getInstance() {
    // create instance by lazy initialization
    // guaranteed to be destroyed
    static SessionData instance;
    
    return instance;
}