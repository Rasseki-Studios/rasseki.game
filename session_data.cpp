#include "session_data.h"
#include "mapdata.h"

bool LocationData::enterLocation(std::string name) {
    if (!ID.empty()) {
        surfMap.~SurfaceMapData();
        evMap.~evMap();
    };
    bool surfMapSuccess = surfMap.initMatrix(name);
    bool evMapSuccess = evMap.initMatrix();
    return surfMapSuccess && evMapSuccess;

}

LocationData::LocationData(std::string locationName) {
    // ID = locationName;
    enterLocation(ID);
}

SessionData& SessionData::getInstance() {
    // create instance by lazy initialization
    // guaranteed to be destroyed
    static SessionData instance;
    
    return instance;
}