#include "mapscanner.h"
#include "libs/EasyBMP/EasyBMP.h"
#include <unordered_set>

// enumeration representing uniqe color on the bmp file
enum rgbColor {
/*
*/
    red_color = 255000000, 
    yellow_color = 255255000, 
    green_color = 255000, 
    white_color = 255255255,

    blue_color = 255, 
    black_color = 0,
    bloody_color = 128000000,
    brown_color = 128128000,
    cyan_color = 128128,
    gold_color = 255255000,
    light_grey_color = 192192192,
    grey_color = 128128128
};

// simple enumeration for storing map in memory
// enum mapColor {black, red, yellow, blue, green, white};
enum mapColor {black, field, road};


bool MapScanner::InitMatrix(const std::string filename) {
    std::unordered_set<int> set;
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
                case black_color:             
                    tempMatrix[i][j] = black;
                    break;
                case bloody_color:               
                    tempMatrix[i][j] = black;
                    break;
                case blue_color:            
                    tempMatrix[i][j] = black;
                    break;
                case gold_color:              
                    tempMatrix[i][j] = road;
                    break;
                // case white_color:
                //     tempMatrix[i][j] = black;
                //     break;                    
                default: 
                    tempMatrix[i][j] = field;
                    break;
            }
        set.insert(intColor);
        }
    }
    for (auto it = set.begin(); it != set.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
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