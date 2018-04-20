#include "mapdata.h"

#include "libs/EasyBMP/EasyBMP.h"

int SurfaceData::mapWidth = 0;
int SurfaceData::mapHeight = 0;
short** SurfaceData::surfaceMatrix = nullptr;

SurfaceData::~SurfaceData() {
    for (int i = 0; i < mapHeight; i++) {
        delete [] surfaceMatrix[i];
    }
    delete [] surfaceMatrix;
}

short SurfaceData::getSurface(coord point) {
    return surfaceMatrix[point.x][point.y];
}

bool SurfaceData::initMatrix(const std::string filename) {
    BMP map;
    if (!map.ReadFromFile(filename.c_str())) return false; 
    mapWidth = map.TellWidth();
    mapHeight = map.TellHeight();
    int intColor; // 9-digit RGB representation
    RGBApixel tempPixel;

    //allocating memory
    int i = 0, j = 0;
    short** tempMatrix = new short* [mapHeight];
    for (i = 0; i < mapHeight; i++) {
        tempMatrix[i] = new short [mapWidth];   
    }

    //row by row scanning of bmp file and transformation colours to surface types
    for (i = 0; i < mapHeight; i++) {
        for (j = 0; j < mapWidth; j++) {
            tempPixel = map.GetPixel(i,j);
            intColor = tempPixel.Red * 1000000 + tempPixel.Green * 1000 + tempPixel.Blue;
            switch (intColor) {
                case 0:                     //black
                    tempMatrix[j][i] = 0;
                    break;
                case 255000000:             //red
                    tempMatrix[j][i] = 1;
                    break;
                case 255255000:             //yellow
                    tempMatrix[j][i] = 2;
                    break;
                case 255:                   //blue
                    tempMatrix[j][i] = 3;
                    break;
                case 255000:                //green
                    tempMatrix[j][i] = 4 ;
                    break;
                case 255255255:             //white
                    tempMatrix[j][i] = 5;
                    break;
            }
        }
    }
    setSurfMatrix(tempMatrix);
    return true;
}

int SurfaceData::getWidth() {
    return mapWidth;
} 

int SurfaceData::getHeight() {
    return mapHeight;
}

void SurfaceData::setSurfMatrix(short** matrix) {
    surfaceMatrix = matrix;
}
