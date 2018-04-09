#include "base.h"
#include <iostream>

//---LOCATED---
Located::Located(int x, int y) {
    this->coordinates.x = x;
    this->coordinates.y = y;
}

coord Located::GetCoord() {
    return coordinates;
}

void Located::SetCoord(coord coordinates) {
    this->coordinates = coordinates;
}

<<<<<<< HEAD
<<<<<<< HEAD
// ---MOVABLE---
Movable::Movable(int x, int y) : Located(x, y){}
=======
//---MOVEBLE---
Moveble::Moveble(int x, int y) : Located(x, y) {}
>>>>>>> Добавлены новые классы предметов (subjects .h/.cpp).

void Movable::Move(coord destination) {
    std::cout << destination.x << " - " << destination.y << std::endl;
=======

//---MOVEBLE---
Movable::Movable(coord coordinates, short speed) : Located(coordinates.x, coordinates.y) {
    this->speed = speed;
}

void Movable::Move(coord destination) {
    //движение
>>>>>>> Переименованны MovAble. Изменены конструкторы классов в subjects. Удален using ns std. В GetArtifact() возвращается указатель на артефакт. Добавлены Get/Set.
}

short Movable::GetSpeed() {
    return speed;
}


//---ITEM---
Item::Item(std::string name, short level) {
    this->name = name;
    this->level = level;
}

short Item::GetId() {
    return id;
}

std::string Item::GetName() {
    return name;
}

short Item::GetLevel() {
    return level;
}