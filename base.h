#ifndef BASE_H
#define BASE_H

#include <string>
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include <functional>
>>>>>>> abstract class Action added
=======
#include <vector>
>>>>>>> Обновленный base.h

struct coord {
    int x;
    int y;
};

class Located {
public:
    Located(int, int);
    coord GetCoord();
    void SetCoord(coord);
protected:
    coord coordinates;
};

<<<<<<< HEAD
<<<<<<< HEAD
class Movable : Located {
=======
class Moveble : public Located {
>>>>>>> Добавлены новые классы предметов (subjects .h/.cpp).
public:
    Movable(int, int);
=======
class Movable : public Located {
public:
    Movable(coord, short);
<<<<<<< HEAD
>>>>>>> Переименованны MovAble. Изменены конструкторы классов в subjects. Удален using ns std. В GetArtifact() возвращается указатель на артефакт. Добавлены Get/Set.
    void Move(coord);
    short GetSpeed();
protected:
    int_fast8_t speed;
=======
    bool Move(coord);
    coord Step();
    short GetSpeed();
protected:
    std::vector<coord> path;
    short speed;
>>>>>>> Обновленный base.h
};

class Item {
<<<<<<< HEAD
public:
    Item(std::string, short);
    short GetId();
    std::string GetName();
    short GetLevel();
protected:
    short id;
=======
    int_fast8_t id;
>>>>>>> short chenged to int_fast8_t
    std::string name;
    int_fast8_t level;
};

<<<<<<< HEAD
#endif //BASE_H
=======
class Action {
    int_fast8_t duration;
    std::string diaryNote;
    // universal function template
    template <class Func, class... Args> std::function<Func(Args...)> act();
};

#endif  // BASE_H
>>>>>>> abstract class Action added
