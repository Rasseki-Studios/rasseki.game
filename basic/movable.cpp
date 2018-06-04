#include "movable.h"
#include "session_data.h"

#include <fstream>
#include <iostream>
using std::cout;
using std::endl;

// hardcode defines. will be removed soon
#define WALL 0    //непроходимая ячейка
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

std::vector<Coord> WaveAlgorithm::GetPath(Coord start, Coord dest) {
    std::vector<Coord> emptyVector(0);

    cout << "dest coord is " << dest << " " << endl;
    cout << "terrain index there is " << (int)dataMap[dest] << endl;

    if (!dataMap.CoordIsValid(start)
    || !dataMap.CoordIsValid(dest)
    || dataMap[start] == WALL
    || dataMap[dest] == WALL) {
        cout << "Check at algorithm start failed" << endl;
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
                if (waveMap[current] != 0) continue;
                if (dataMap[current] != WALL) {
                    newEdge->push_back(current);
                    waveMap[current] = waveIndex;
                } else continue;
                if (current == dest) {
                    delete newEdge;
                    delete waveEdge;
                    return GetBackPath(dest);
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

std::vector<Coord> WaveAlgorithm::GetBackPath(Coord dest) {
    //восстановление пути

    int length = waveMap[dest];
    //длина кратчайшего пути из dest в dest

    Coord step(dest);  //текущий шаг
    cout << length << endl;
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