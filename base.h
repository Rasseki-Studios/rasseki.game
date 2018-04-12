#ifndef BASE_H
#define BASE_H

#include <string>
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include <functional>
>>>>>>> abstract class Action added
=======
=======
>>>>>>> const and inline added, pedantic lines swaps made
#include <vector>
>>>>>>> Обновленный base.h


using str = std::string;

struct coord {
    int x;
    int y;
};

class Located {
public:
    Located(int, int);
    void SetCoord(coord);
    coord GetCoord() const;
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
    short GetSpeed() const;
protected:
<<<<<<< HEAD
    std::vector<coord> path;
    short speed;
>>>>>>> Обновленный base.h
=======
    short speed;
    std::vector<coord> path;
>>>>>>> const and inline added, pedantic lines swaps made
};

class Item {
<<<<<<< HEAD
public:
<<<<<<< HEAD
<<<<<<< HEAD
    Item(std::string, int, short);
    short GetId();
    std::string GetName();
    short GetLevel();
=======
    Item(std::string, short);
=======
    Item(str, short);
<<<<<<< HEAD
>>>>>>> ID are strings now, std::string can be used as str
    short GetId() const;
=======
    str GetId() const;
>>>>>>> IDs are now strings
    str GetName() const;
    short GetLevel() const;
>>>>>>> const and inline added, pedantic lines swaps made
protected:
<<<<<<< HEAD
<<<<<<< HEAD
    short id;
<<<<<<< HEAD
=======
    int_fast8_t id;
>>>>>>> short chenged to int_fast8_t
=======
    int id;
>>>>>>> Добавлены методы рассчета маршрута Move() и перемещения Step(). Id добавлен в конструктор Item для генерации из вне.
    std::string name;
    int_fast8_t level;
=======
=======
    str id;
>>>>>>> IDs are now strings
    str name;
    short level;
>>>>>>> ID are strings now, std::string can be used as str
};

<<<<<<< HEAD
#endif //BASE_H
=======
class Action {
public:
    Action(short, str, str, str, str);
    void run() const;
private:
    short duration;
    str subjectID;  // Item *subject in future
    str command;  // Converts in function in run()
    str objectID;  // Item *object in future
    str diaryNote;
};

class IFactory {
    virtual Item* create() = 0;
    // virtual void update();
};

#endif  // BASE_H
>>>>>>> abstract class Action added
