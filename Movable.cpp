#include "Location.h"

//=====================
//КОНФИГУРАЦИОННЫЙ ФАЙЛ
const int WALL = -1;    //непроходимая ячейка
const int BLANK = -2;   //свободная непомеченная ячейка
//=====================

Movable::Movable(coord coordinates, short speed) : Located(coordinates), speed(speed) {}

bool Movable::Move(coord destination) {
    path.clear();   //очищаем текущий маршрут для пересчета
    //===========================
    //ПОЛУЧЕНИЕ КУСКА КАРТЫ
    int width = 0;  //ширина рабочего поля
    int height = 0;  //высота рабочего поля
    int **map;  //картa
    //в дальнейшем будем использовать ф-цию для получения данных
    //Map.getPart(map, &width, &height)

    //эмуляция карты
    map = new int*[width];
    for (int j = 0; j < width; ++j) {
        map[j] = new int[height];
        for (int i = 0; i < height; ++i) {
            map[j][i] = BLANK;
        }
    }
    //===========================

    if (map[coordinates.x][coordinates.y] == WALL || map[destination.x][destination.y] == WALL) {
        return false;   //если стартовая или конечная ячейка непроходима
    }

    int len = wave(map, width, height, destination);

    for (int k = 0; k < width; ++k) {
        delete map[k];
    }
    delete [] map;
    return len >= 0 ? true : false;  //алгоритм поиска пути, формирует вектор path
}

coord Movable::Step() {
    if (!path.empty()) {
        coordinates = path[path.size() - 1];
        path.pop_back();
    }
    return coordinates;
}

short Movable::GetSpeed() const {
    return speed;
}

int Movable::wave(int** map, int width, int height, coord destination) {
    const int offset = 4;
    int dx[offset] = {1, 0, -1, 0};   //смещения, соответствующие соседям ячейки
    int dy[offset] = {0, 1, 0, -1};   //справа, снизу, слева и сверху
    //распространение волны
    bool stop = false;
    int d = 0;
    map[coordinates.x][coordinates.y] = 0;  //стартовая ячейка помечена 0
    do {
        stop = true;    //предполагаем, что все свободные клетки уже помечены
        for (int x = 0; x < height; x++) {
            for (int y = 0; y < width; y++) {
                if (map[x][y] == d) {   //ячейка (x, y) помечена числом d
                    for (int k = 0; k < offset; k++) {   //проходим по всем непомеченным соседям
                        coord step{x + dx[k], y + dy[k]};
                        if ((step.x >= 0 && step.x < width) && (step.y >= 0 && step.y < height) &&
                            map[step.x][step.y] == BLANK) {
                            stop = false;   //найдены непомеченные клетки
                            map[step.x][step.y] = d + 1;    //распространяем волну
                        }
                    }
                }
            }
        }
        d++;
    } while (!stop && map[destination.x][destination.y] == BLANK);

    if (map[destination.x][destination.y] == BLANK) {
        return -1;   //путь не найден
    }

    //восстановление пути
    int len = map[destination.x][destination.y];    //длина кратчайшего пути из coordinates в destination
    int x = destination.x;
    int y = destination.y;
    path.reserve(len);
    d = len;
    while (d > 0) {
        path.push_back({x, y});   //записываем ячейку в путь
        d--;
        for (int k = 0; k < offset; k++) {
            coord step{x + dx[k], y + dy[k]};
            if ((step.x >= 0 && step.x < width) && (step.y >= 0 && step.y < height) && map[step.x][step.y] == d) {
                x = step.x;
                y = step.y; //переходим в ячейку, которая на 1 ближе к старту
                break;
            }
        }
    }
    return len;
}