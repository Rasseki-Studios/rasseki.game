#include "map.h"

MapData::MapData(const char* filename) {
    initSurfMatrix(filename);
}

MapData::~MapData() {
    for (int i = 0; i < mapHeight; i++) {
        delete [] surfaceMatrix[i];
    }
    delete [] surfaceMatrix;
}

bool MapData::initSurfMatrix(const char* filename) {
    BMP map;
    if (!map.ReadFromFile(filename)) return false; 
    mapWidth = map.TellWidth();
    mapHeight = map.TellHeight();
    int intColor; // 9-digit RGB representation
    RGBApixel tempPixel;

    //allocating memory
    int i = 0, j = 0;
    surfaceMatrix = new short* [mapHeight];
    for (i = 0; i < mapHeight; i++) {
        surfaceMatrix[i] = new short [mapWidth];        
    }

    //row by row scanning of bmp file and transformation colours to surface types
    for (i = 0; i < mapHeight; i++) {
        for (j = 0; j < mapWidth; j++) {
            tempPixel = map.GetPixel(i,j);
            intColor = tempPixel.Red * 1000000 + tempPixel.Green * 1000 + tempPixel.Blue;
            switch (intColor) {
                case 0:
                    surfaceMatrix[i][j] = 0;
                    break;
                case 255255255:
                    surfaceMatrix[i][j] = 1;
                    break;
                case 255000000:
                    surfaceMatrix[i][j] = 2;
                    break;
                case 255000:
                    surfaceMatrix[i][j] = 3;
                    break;
                case 255:
                    surfaceMatrix[i][j] = 4;
                    break;
            }
        }
    }

    return true;
}