#include "mapscanner.h"
#include "libs/EasyBMP/EasyBMP.h"

bool MapScanner::InitMatrix(const std::string filename) {
    BMP map;
    X data;
    if (!map.ReadFromFile(filename.c_str())) return false; 
    data.mapWidth = map.TellWidth();
    data.mapHeight = map.TellHeight();
    int intColor; // 9-digit RGB representation
    RGBApixel tempPixel;

    //allocating memory
    int i = 0, j = 0;
    short** tempMatrix = new short* [data.mapHeight];
    for (i = 0; i < data.mapHeight; i++) {
        tempMatrix[i] = new short [data.mapWidth];   
    }

    //row by row scanning of bmp file and transformation colours to surface types
    for (i = 0; i < data.mapHeight; i++) {
        for (j = 0; j < data.mapWidth; j++) {
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
    return true;
}

X& MapScanner::getMap(const str filename) {
    if (InitMatrix(filename)) return data;
    else {
        throw "error during file scanning";
        return data;
    } 
}