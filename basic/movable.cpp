#include "movable.h"
#include "session_data.h"

#include <iostream>
using std::cout;
using std::endl;

// hardcode defines. will be removed soon
#define WALL 10    //непроходимая ячейка
#define DIRT 1    //затруднённая проходимость (грязь)
#define ROAD 2   //отличная проходимость (дорога)

using namespace SessionData;

Movable::Movable(Coord coordinates, short speed)
:
Located(coordinates), speed(speed) {}

int Movable::Move(Coord destination) {
    //очищаем текущий маршрут для пересчета
    path.clear();
    WaveAlgorithm alg;
    // алгоритм поиска пути, формирует вектор path
    path = alg.GetPath(coordinates, destination);
    return path.size();
}

Coord Movable::Step() {
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
:
width( surfaceData.getWidth() ),
height( surfaceData.getHeight() ),
dataMap( surfaceData.getMap() ),
waveMap(width, height, true) {}

    // Reload();
// void WaveAlgorithm::Reload() {
// }

std::vector<Coord> WaveAlgorithm::GetPath(Coord start, Coord dest) {
    std::vector<Coord> emptyVector(0);

    // cout << "start:" << start.x << " " << start.y << endl;
    // cout << "dest:" << dest.x << " " << dest.y << endl;
    // cout << "start by getSurf: " << surfaceData.getSurface(start) << endl;
    // cout << "dest by getSurf: " << surfaceData.getSurface(dest) << endl;
    // cout << "start surf is " << dataMap[start.x][start.y] << endl;
    // cout << "dest surf is " << dataMap[dest.x][dest.y] << endl;
    if (dataMap[start] == WALL
    || dataMap[dest] == WALL) {
        cout << "Check at algorithm start failed" << endl;
    // + сюда добавить проверку на валидность конечной координаты
        //если стартовая или конечная ячейка непроходима
        return emptyVector;
    }

    auto waveEdge = new std::vector<Coord>();
    waveEdge->push_back(start);

    short waveIndex = 1;
    waveMap[start] = waveIndex;

    while(waveEdge->size() != 0) {
        auto newEdge = new std::vector<Coord>();
        waveIndex++;
        for (auto edge : *waveEdge) {
            for (auto neighbour : neighbours) {
                Coord current(edge.x + neighbour.x, edge.y + neighbour.y);
                if (!waveMap.CoordIsValid(current)) continue;
                cout << current.x << " " << current.y << endl;
                int a = (int)waveMap[current];
                cout << (int)waveMap[current] << endl;
                cout << "AM I HERE???" << endl;
                if (/* waveMap[current] *//* a != 0 */1) {
                    cout << "i am alive" << endl;
                    continue;
                }
                if (current == dest) {
                    waveMap[current] = waveIndex;
                    delete newEdge;
                    delete waveEdge;
                    return GetBackPath(/* start,  */dest);
                } else if (dataMap[current] != WALL) {
                    newEdge->push_back(current);
                    waveMap[current] = waveIndex;
                }
            }
        }
        delete waveEdge;
        waveEdge = newEdge;
    }

    cout << "no path found" << endl;
    // no path found
    return emptyVector;
}

std::vector<Coord> WaveAlgorithm::GetBackPath(/* Coord start,  */Coord dest) {
    //восстановление пути

    int length = waveMap[dest];
    //длина кратчайшего пути из dest в dest

    Coord step(dest.x, dest.y);  //текущий шаг
    std::vector<Coord> path(length);  //выделяем место под шаги

    for (int i = length; i != 1; i--) {
        for (auto it : neighbours) {
            Coord current(step.x + it.x, step.y + it.y);
            if (!surfaceData.CoordIsValid(current)) continue;
            if (waveMap[current] == i - 1) {
                step = current;
                break;
            }
        }
        path.at(length - i) = step;
    }

    return path;
}