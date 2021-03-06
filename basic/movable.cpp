#include "movable.h"
#include "session_data.h"

#include <iostream>
using std::cout;
using std::endl;

#include <queue>

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



/* ************************** LEE  WAVE  ALGORITHM **************************** */
/* ****************************** by stanford ********************************* */

#define WALL 0    //непроходимая ячейка

WaveAlgorithm::WaveAlgorithm()
:
width( surfaceData.getWidth() ),
height( surfaceData.getHeight() ),
dataMap( surfaceData.getMap() ),
waveMap(width, height, true) {}

std::vector<Coord> WaveAlgorithm::GetPath(Coord start, Coord dest) {
    std::vector<Coord> emptyVector(0);

    cout << "start coord is " << start << " " << endl;
    cout << "destination coord is " << dest << " " << endl;
    cout << "terrain index there is " << (int)dataMap[dest] << endl;

    if (!dataMap.CoordIsValid(start)
    ||  !dataMap.CoordIsValid(dest)
    ||  dataMap[start] == WALL
    ||  dataMap[dest] == WALL) {
        cout << "Check at algorithm start failed" << endl;
        return emptyVector;
    }

    std::queue<Coord> waveEdge;
    waveEdge.emplace(start);

    short waveIndex = 1;
    waveMap[start] = waveIndex;

    for (Coord edge = waveEdge.front();
        !waveEdge.empty();
        edge = waveEdge.front()
    ) {
        waveEdge.pop();
        for (auto it : neighbours) {
            Coord current(edge.x + it.x, edge.y + it.y);
            if (waveMap.CoordIsValid(current)
            && waveMap[current] == 0
            && dataMap[current] != WALL) {
                waveEdge.emplace(current);
                waveMap[current] = waveMap[edge] + 1;
            } else continue;
            if (current == dest) {
                return GetBackPath(dest);
            }
        }
    }
    cout << "no path found" << endl;
    // no path found
    return emptyVector;
}

std::vector<Coord> WaveAlgorithm::GetBackPath(Coord dest) {
    int length = waveMap[dest];

    Coord step(dest);  // current step
    // cout << "shortest path length is " << length << endl;
    std::vector<Coord> path(length - 1);
    path.at(0) = dest;

    for (int i = length; i != 2; i--) {
        for (auto it : neighbours) {
            Coord current(step.x + it.x, step.y + it.y);
            if (!surfaceData.CoordIsValid(current)) continue;
            if (waveMap[current] == i - 1) {
                path.at(length - i + 1) = current;
                step = current;
                break;
            }
        }
    }

    return path;
}