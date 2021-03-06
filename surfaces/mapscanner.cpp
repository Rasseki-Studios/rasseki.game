#include "mapscanner.h"
#include "matrix.hpp"
#include <unordered_set>

// enumeration representing uniqe color on the bmp file
enum rgbColor {
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

MapScanner::MapScanner(const str filename) {
    if (!map.ReadFromFile(filename.c_str())) {
        throw std::invalid_argument( "File \"" + filename  + "\" does not exist\n");
    }
}

int MapScanner::getColor(Coord point) {
    RGBApixel tempPixel;    
    tempPixel = map.GetPixel(point.y, point.x);
    int intColor = tempPixel.Red * 1000000 + tempPixel.Green * 1000 + tempPixel.Blue;
    return intColor;
}

void MapScanner::FillMatrix(Matrix<char>& matrix) {
    std::unordered_set<int> set;

    int mapWidth = map.TellWidth();
    int mapHeight = map.TellHeight();
    int intColor; // 9-digit RGB representation

    //row by row scanning of bmp file and transformation colours to surface types
    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWidth; j++) {
            intColor = getColor({i, j});
            switch (intColor) {
                // as for now we mark several surfaces as unwalkable
                case black_color:
                    matrix[{j, i}] = black; 
                    break;
                case bloody_color:
                    matrix[{j, i}] = black;
                    break;
                case blue_color:
                    matrix[{j, i}] = black;
                    break;
                case gold_color:
                    matrix[{j, i}] = road;
                    break;
                default: 
                    matrix[{j, i}] = field;
                    break;
            }
        set.insert(intColor);
        }
    }
    // for (auto it = set.begin(); it != set.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    std::cout << std::endl;
}
