#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

#include <QPoint>
#include <QDebug>
#include <thread>


//расширение класса QGraphicsView
class MapView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MapView(QWidget *parent = 0);
    ~MapView();

signals:
    //void mousePressEvent(QMouseEvent *releaseEvent);
    void passCoord(const QPointF& point);

public slots:
    void slotAlarmTimer();  //таймер для перерисовки виджета

private:
    QGraphicsScene *mapScene;       //объявляем сцену для отрисовки
    QGraphicsItem *hero;    //объявляем первую группу элементов
    //QGraphicsItemGroup *group_2;    //объявляем вторую группу элементов
    QTimer *timer;  //таймер для задержки отрисовки.
    std::thread td;

private:
    void resizeEvent(QResizeEvent *event);  //перегружаем событие изменения размера окна, чтобы перехватывать его

    void deleteItemsFromGroup(QGraphicsItemGroup *hero); //метод для удаления всех элементов из группы элементов

    void mousePressEvent(QMouseEvent *mousePressEvt);   //метод для отлавливания нажатий игрока мышкой на карту
};

#endif // MAPVIEW_H
