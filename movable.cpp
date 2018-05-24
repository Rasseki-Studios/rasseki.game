#include "movable.h"
#include "session_data.h"

// hardcode defines. will be removed soon

#define WALL 0    //непроходимая ячейка
#define DIRT 5    //затруднённая проходимость (грязь)
#define ROAD 10   //отличная проходимость (дорога)

using namespace SessionData;

Movable::Movable(coord coordinates, short speed)
        :
        Located(coordinates), speed(speed) {}

int Movable::Move(coord destination) {
    path.clear();   //очищаем текущий маршрут для пересчета
    WaveAlgorithm alg; 
    path = alg.GetPath(coordinates, destination);  //алгоритм поиска пути, формирует вектор path
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

WaveAlgorithm::WaveAlgorithm() 
: dataMap(nullptr), waveMap(nullptr) {
    Reload();
}

void WaveAlgorithm::Reload() {
    width = surfaceData.getWidth();
    height = surfaceData.getHeight();
    dataMap = surfaceData.getMap();
    waveMap = new short*[width];
    for (int i = 0; i < height; i++) {
        waveMap[i] = new short[width]();
    }
}

std::vector<coord> WaveAlgorithm::GetPath(coord start, coord dest) {
    std::vector<coord> emptyVector(0);

    if (dataMap[start.x][start.y] == WALL
    || dataMap[dest.x][dest.y] == WALL) { 
    // + сюда добавить проверку на валидность конечной координаты
        //если стартовая или конечная ячейка непроходима
        return emptyVector;
    }

    std::vector<coord> *waveEdge;
    waveEdge->push_back(start);

    short waveIndex = 1;
    waveMap[start.x][start.y] = waveIndex;

    while(waveEdge->size() != 0) {
        std::vector<coord> *newEdge;
        waveIndex++;
        for (auto edge : *waveEdge) {
            for (auto neighbour : neighbours) {
                coord current(edge.x + neighbour.x, edge.y + neighbour.y);
                if (!surfaceData.CoordIsValid(current) ||
                    waveMap[current.x][current.y] != 0) continue;
                if (current == dest) {
                    delete newEdge;
                    delete waveEdge;
                    return GetBackPath(start, dest);
                } else if (dataMap[current.x][current.y] != WALL) {
                    newEdge->push_back(current);
                    waveMap[current.x][current.y] = waveIndex;
                }
            }
        }
        delete waveEdge;
        waveEdge = newEdge;
    }

    // no path found
    return emptyVector;
}

std::vector<coord> WaveAlgorithm::GetBackPath(coord start, coord dest) {
    //восстановление пути

    int length = waveMap[dest.x][dest.y]; 
    //длина кратчайшего пути из dest в dest

    coord step(dest.x, dest.y);  //текущий шаг
    std::vector<coord> path(length);  //выделяем место под шаги

    for (int i = length; i != 1; i--) {
        for (auto it : neighbours) {
            coord current(step.x + it.x, step.y + it.y);
            if (!surfaceData.CoordIsValid(current)) continue;
            if (waveMap[current.x][current.y] == i - 1) {
                step.x = current.x;
                step.y = current.y;
                break;
            }
        }
        path[length] = step;
    }

    for (int i = 0; i < height; i++) {
        delete waveMap[i];
    } delete waveMap;

    return path;
}