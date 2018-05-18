#include "movable.h"
#include "session_data.h"

#define WALL -1    //непроходимая ячейка
#define BLANK -2   //свободная непомеченная ячейка

using namespace SessionData;

Movable::Movable(coord coordinates, short speed) 
:
Located(coordinates), speed(speed) {}

int Movable::Move(coord destination) {
    path.clear();   //очищаем текущий маршрут для пересчета
    Wave alg;
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

Wave::Wave() {
    width = surfaceData.getWidth();
    height = surfaceData.getHeight();
    Reload();
}

void Wave::Reload() {
    map.clear();    
    for (int x = 0; x < width; x++) {
        std::vector<short> temp(height);
        for (int y = 0; y < height; y++) {
            coord point(x, y);
            short pixel = (surfaceData.IsWalkable(point) ? BLANK : WALL);
            temp[y] = pixel;
        }
        map.push_back(temp);
    }
}

std::vector<coord> Wave::Path(coord start, coord dest) {
    if (map[start.x][start.y] == WALL || map[dest.x][dest.y] == WALL) {
        return std::vector<coord>(0);   //если стартовая или конечная ячейка непроходима
    }
    const int offset = 4;
    coord neighbors[offset] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};   //смещения, соответствующие соседям ячейки
    bool stop = false;
    int d = 0;
    map[start.x][start.y] = 0;  //стартовая ячейка помечена 0
    do {
        stop = true;    //предполагаем, что все свободные клетки уже помечены
        for (int x = 0; x != height; x++) {
            for (int y = 0; y != width; y++) {
                if (map[x][y] == d) {   //ячейка (x, y) помечена числом d
                    for (auto neighbor : neighbors) {   //проходим по всем непомеченным соседям
                        coord step{x + neighbor.x, y + neighbor.y};
                        if ((step.x != 0 && step.x != width) && 
                            (step.y != 0 && step.y != height) && 
                            map[step.x][step.y] == BLANK
                        ) {
                            stop = false;   //найдены непомеченные клетки
                            map[step.x][step.y] = d + 1;    //распространяем волну
                        }
                    }
                }
            }
        }
        d++;
    } while (!stop && map[dest.x][dest.y] == BLANK);

    if (map[dest.x][dest.y] == BLANK) {
        return std::vector<coord>(0);   //путь не найден
    }

    //восстановление пути
    int len = map[dest.x][dest.y];    //длина кратчайшего пути из coordinates в dest
    coord place(dest.x, dest.y);  //текущее место рассчета
    std::vector<coord> path(len);  //выделяем место под шаги
    d = len;
    coord allNeighbours[] = {
        { 1,  0}, { 1, -1}, { 0, -1}, {-1, -1},
        {-1,  0}, {-1,  1}, { 0,  1}, { 1, -1}
    }; //смещения, соответствующие соседям ячейки (в том числе и диагональным)
    while (d != 0) {
        // path.push_back(place);   //записываем ячейку в путь
        path[len - d] = place;
        d--;
        for (auto neighbour : allNeighbours) {
            coord step{place.x + neighbour.x, place.y + neighbour.y};
            if ((step.x >= 0 && step.x < width) && (step.y >= 0 && step.y < height) && map[step.x][step.y] == d) {
                place = step;   //переходим в ячейку, которая на 1 ближе к старту
                break;
            }
        }
    }
    return path;
}