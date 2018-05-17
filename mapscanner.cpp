#include "mapscanner.h"
#include "libs/EasyBMP/EasyBMP.h"

// enumeration representing uniqe color on the bmp file
enum rgbColor {
    black_color = 0, 
    red_color = 255000000, 
    yellow_color = 255255000, 
    blue_color = 255, 
    green_color = 255000, 
    white_color = 255255255
};

// simple enumeration for storing map in memory
enum mapColor {black, red, yellow, blue, green, white};

bool MapScanner::InitMatrix(const std::string filename) {
    BMP map;
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
                case black_color:             //black
                    tempMatrix[j][i] = black;
                    break;
                case red_color:               //red
                    tempMatrix[j][i] = red;
                    break;
                case yellow_color:            //yellow
                    tempMatrix[j][i] = yellow;
                    break;
                case blue_color:              //blue
                    tempMatrix[j][i] = blue;
                    break;
                case green_color:             //green
                    tempMatrix[j][i] = green;
                    break;
                case white_color:             //white
                    tempMatrix[j][i] = white;
                    break;
            }
        }
    }
    data.surfaceMatrix = tempMatrix;
    return true;
}

MapData& MapScanner::getMap(str filename) {
    if (InitMatrix(filename)) return data;
    else {
        throw "error during file scanning";
        abort();
        data.mapHeight = -1;
        data.mapWidth = -1;
        return data;
    } 
}