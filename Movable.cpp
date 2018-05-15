#include "Movable.h"

#define WALL -1    //непроходимая ячейка
#define BLANK -2   //свободная непомеченная ячейка

Movable::Movable(coord coordinates, short speed) : Located(coordinates), speed(speed) {}

bool Movable::Move(coord destination) {
    path.clear();   //очищаем текущий маршрут для пересчета

    int width = 100;  //ширина рабочего поля
    int height = 100;  //высота рабочего поля
    int **map = nullptr;  //картa
    //в дальнейшем будем использовать ф-цию для получения данных
    //Map.getPart(map, &width, &height)


    //===========================
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


    //===========================
    //удаление будет производиться в той же области, где и создание
    for (int k = 0; k < width; ++k) {
        delete map[k];
    }
    delete [] map;
    //===========================


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

int Movable::wave(int **map, int width, int height, coord destination) {
    const int offset = 4;
    coord neighbors[offset] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};   //смещения, соответствующие соседям ячейки
    bool stop = false;
    int d = 0;
    map[coordinates.x][coordinates.y] = 0;  //стартовая ячейка помечена 0
    do {
        stop = true;    //предполагаем, что все свободные клетки уже помечены
        for (int x = 0; x < height; x++) {
            for (int y = 0; y < width; y++) {
                if (map[x][y] == d) {   //ячейка (x, y) помечена числом d
                    for (auto neighbor : neighbors) {   //проходим по всем непомеченным соседям
                        coord step{x + neighbor.x, y + neighbor.y};
                        if ((step.x >= 0 && step.x < width) && (step.y >= 0 && step.y < height) && map[step.x][step.y] == BLANK) {
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
    coord place(destination.x, destination.y);  //текущее место рассчета
    path.reserve(len);  //выделяем место под шаги
    d = len;
    while (d > 0) {
        path.push_back(place);   //записываем ячейку в путь
        d--;
        for (auto neighbor : neighbors) {
            coord step{place.x + neighbor.x, place.y + neighbor.y};
            if ((step.x >= 0 && step.x < width) && (step.y >= 0 && step.y < height) && map[step.x][step.y] == d) {
                place = step;   //переходим в ячейку, которая на 1 ближе к старту
                break;
            }
        }
    }
    return len;
}