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
    QGraphicsItemGroup *group_1;    //объявляем первую группу элементов
    QGraphicsItemGroup *group_2;    //объявляем вторую группу элементов
    QTimer *timer;  //таймер для задержки отрисовки.

private:
    void resizeEvent(QResizeEvent *event);  //перегружаем событие изменения размера окна, чтобы перехватывать его

    void deleteItemsFromGroup(QGraphicsItemGroup *group_1); //метод для удаления всех элементов из группы элементов

    void mousePressEvent(QMouseEvent *mousePressEvt);   //метод для отлавливания нажатий игрока мышкой на карту
};

#endif // MAPVIEW_H
