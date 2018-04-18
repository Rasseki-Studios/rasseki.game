#include "Location.h"

Movable::Movable(coord coordinates, short speed) : Located(coordinates) {
    this->speed = speed;
}

bool Movable::Move(coord destination) {
    path.clear();
    const int WALL = -1;    //непроходимая ячейка
    const int BLANK = -2;   //свободная непомеченная ячейка

    //===========================
    //ПОЛУЧЕНИЕ КУСКА КАРТЫ
    const int W = 100;  //ширина рабочего поля
    const int H = 100;  //высота рабочего поля
    int map[W][H];  //карта

    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            map[i][j] = BLANK;
        }
    }
    //===========================

    if (map[coordinates.x][coordinates.y] == WALL || map[destination.x][destination.y] == WALL) {    //если стартовая или конечная ячейка непроходима
        return false;
    }

    int dx[4] = {1, 0, -1, 0};   //смещения, соответствующие соседям ячейки
    int dy[4] = {0, 1, 0, -1};   //справа, снизу, слева и сверху
    //распространение волны
    bool stop = false;
    int d = 0;
    map[coordinates.x][coordinates.y] = 0;  //стартовая ячейка помечена 0
    do {
        stop = true;    //предполагаем, что все свободные клетки уже помечены
        for (int x = 0; x < H; x++) {
            for (int y = 0; y < W; y++) {
                if (map[x][y] == d) {   //ячейка (x, y) помечена числом d
                    for (int k = 0; k < 4; k++) {   //проходим по всем непомеченным соседям
                        coord step{x + dx[k], y + dy[k]};
                        if ((step.x >= 0 && step.x < W) && (step.y >= 0 && step.y < H) && map[step.x][step.y] == BLANK) {
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
        return false;   //путь не найден
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
        for (int k = 0; k < 4; k++) {
            coord step{x + dx[k], y + dy[k]};
            if ((step.x >= 0 && step.x < W) && (step.y >= 0 && step.y < H) && map[step.x][step.y] == d) {
                x = step.x;
                y = step.y; //переходим в ячейку, которая на 1 ближе к старту
                break;
            }
        }
    }
    return true;
}

coord Movable::Step() {
    if (path.empty()) {
        return {0, 0};  //???
    }
    coordinates = path[path.size() - 1];
    path.pop_back();
    return coordinates;
}

short Movable::GetSpeed() const {
    return speed;
}
