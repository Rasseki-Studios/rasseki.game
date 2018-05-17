#include "Movable.h"

#define WALL -1    //непроходимая ячейка
#define BLANK -2   //свободная непомеченная ячейка

SurfaceData SD(1000,1000);

Movable::Movable(coord coordinates, short speed) : Located(coordinates), speed(speed) {}

int Movable::Move(coord destination) {
    path.clear();   //очищаем текущий маршрут для пересчета
    Wave alg(&SD);
    path = alg.Path(coordinates, destination);  //алгоритм поиска пути, формирует вектор path
    return path.size();
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

Wave::Wave(SurfaceData *surface) : surface(surface) {
    width = surface->getWidth();
    height = surface->getHeight();
    Reload();
}

void Wave::Reload() {
    map.clear();
    for (int x = 0; x < width; x++) {
        std::vector<short> temp(height);
        for (int y = 0; y < height; y++) {
            coord point(x, y);
            short pixel = (surface->IsWalkable(point) ? BLANK : WALL);
            temp[y] = pixel;
        }
        map.push_back(temp);
    }
}

std::vector<coord> Wave::Path(coord coordinates, coord destination) {
    if (map[coordinates.x][coordinates.y] == WALL || map[destination.x][destination.y] == WALL) {
        return std::vector<coord>(0);   //если стартовая или конечная ячейка непроходима
    }
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
        return std::vector<coord>(0);   //путь не найден
    }

    //восстановление пути
    int len = map[destination.x][destination.y];    //длина кратчайшего пути из coordinates в destination
    coord place(destination.x, destination.y);  //текущее место рассчета
    std::vector<coord> path(len);  //выделяем место под шаги
    d = len;
    while (d > 0) {
        //path.push_back(place);   //записываем ячейку в путь
        path[len - d] = place;
        d--;
        for (auto neighbor : neighbors) {
            coord step{place.x + neighbor.x, place.y + neighbor.y};
            if ((step.x >= 0 && step.x < width) && (step.y >= 0 && step.y < height) && map[step.x][step.y] == d) {
                place = step;   //переходим в ячейку, которая на 1 ближе к старту
                break;
            }
        }
    }
    return path;
}