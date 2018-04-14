//This code uses free-distributed library "EasyBMP-1.06". 
//https://sourceforge.net/projects/easybmp/
//Great thanks to the authors of this pretty useful tool.

#include "mapdata.h"
#include "libs/EasyBMP/EasyBMP.h"

int MapData::mapWidth = 0;
int MapData::mapHeight = 0;
short** MapData::surfaceMatrix = nullptr;

MapData::~MapData() {
    for (int i = 0; i < mapHeight; i++) {
        delete [] surfaceMatrix[i];
    }
    delete [] surfaceMatrix;
}

short MapData::getSurfaceType(coord point) {
    return surfaceMatrix[point.x][point.y];
}

bool MapData::initSurfMatrix(const std::string filename) {
    BMP map;
    if (!map.ReadFromFile(filename.c_str())) return false; 
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
                case 0:                     //black
                    surfaceMatrix[j][i] = 0;
                    break;
                case 255000000:             //red
                    surfaceMatrix[j][i] = 1;
                    break;
                case 255255000:             //yellow
                    surfaceMatrix[j][i] = 2;
                    break;
                case 255:                   //blue
                    surfaceMatrix[j][i] = 3;
                    break;
                case 255000:                //green
                    surfaceMatrix[j][i] = 4 ;
                    break;
                case 255255255:             //white
                    surfaceMatrix[j][i] = 5;
                    break;
            }
        }
    }

    return true;
}

int MapData::getWidth() {
    return mapWidth;
} 

int MapData::getHeight() {
    return mapHeight;
}
