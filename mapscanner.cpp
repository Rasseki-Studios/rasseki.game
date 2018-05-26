#include "mapscanner.h"
#include "matrix.h"
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

void MapScanner::FillMatrix(const str filename, Matrix<char>& matrix) {
    std::unordered_set<int> set;
    BMP map;
    map.ReadFromFile(filename.c_str());

    int mapWidth = map.TellWidth();
    int mapHeight = map.TellHeight();
    int intColor; // 9-digit RGB representation
    RGBApixel tempPixel;

    // //allocating memory
    // short** tempMatrix = new short* [mapHeight];
    // for (i = 0; i < data.mapHeight; i++) {
    //     tempMatrix[i] = new short [data.mapWidth];   
    // }

    // Matrix<char> matrix (mapWidth, mapHeight);

    //row by row scanning of bmp file and transformation colours to surface types
    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWidth; j++) {
            tempPixel = map.GetPixel(i,j);
            intColor = tempPixel.Red * 1000000 + tempPixel.Green * 1000 + tempPixel.Blue;
            switch (intColor) {
                case black_color:
                    matrix.setValue({i, j}, black);
                    break;
                case bloody_color:               
                    matrix.setValue({i, j}, black);
                    break;
                case blue_color:            
                    matrix.setValue({i, j}, black);
                    break;
                case gold_color:              
                    matrix.setValue({i, j}, road);
                    break;
                // case white_color:
                //     matrix.setValue({i, j}, black);
                //     break;                    
                default: 
                    matrix.setValue({i, j}, field);                    
                    break;
            }
        set.insert(intColor);
        }
    }
    for (auto it = set.begin(); it != set.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // surfaceMatrix = tempMatrix;
    // return matrix;
}
