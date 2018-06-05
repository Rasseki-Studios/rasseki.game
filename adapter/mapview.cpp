#include "mapview.h"
#include "gamewindow.h"
#include "libAdapter.h"

#include <thread>
#include "paths.h"
#include "game_settings.h"

MapView::MapView(QWidget *parent)
    : QGraphicsView(parent)
{
    //настройка отображения виджета и его содержимого
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //отключим скроллбар по горизонтали
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   //отключим скроллбар по вертикали

    Coord end = EndOfMap();
    width_end = end.x;
    height_end = end.y;

    mapScene = std::shared_ptr<QGraphicsScene>(new QGraphicsScene(this));   //инициализируем сцену для отрисовки

    QPixmap img_m(img_map.c_str()); //карта
    img_m.scaled(width(), height(), Qt::KeepAspectRatio);
    mapScene->setBackgroundBrush(QBrush(img_m));    //устанавливаем Background виджета (изображение карты)

    QPixmap img_h(img_hero.c_str());  //герой

    //QGraphicsItem *a = ;
    hero = std::shared_ptr<QGraphicsItem>(mapScene->addPixmap(img_h.scaled(70, 70, Qt::KeepAspectRatio)));

    Coord pos = HeroCoords();   //установливаем положение героя
    QPoint point(pos.x, pos.y);
    hero->setPos(point);
    int width = this->width();
    int height = this->height();

    int x = border(pos.x, width, width_end);
    int y = border(pos.y, height, height_end);
    mapScene->setSceneRect(x, y, width, height);

    setScene(mapScene.get()); //устанавливаем сцену в виджет

    //необходимо некоторое время, чтобы родительский слой развернулся, чтобы принимать от него адекватные параметры ширины и высоты
    timer = std::shared_ptr<QTimer>(new QTimer());   //инициализируем Таймер
    connect(timer.get(), SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));    //подключаем слот для отрисовки к таймеру
    timer->start(timer_delay);   //стартуем таймер
}

MapView::~MapView()
{
    if (td.joinable()) {
        td.join();
    }
}

void MapView::slotAlarmTimer()
{
    Coord pos = HeroCoords();   //устанавливаем героя на актуальную позицию
    QPoint point(pos.x - hero_offset, pos.y - hero_offset);
    hero.get()->setPos(point);

    int width = this->width();      //определяем ширину нашего виджета
    int height = this->height();    //определяем высоту нашего виджета

    int x = border(pos.x, width, width_end);
    int y = border(pos.y, height, height_end);
    mapScene->setSceneRect(x, y, width, height);
}

//этим методом перехватываем событие изменения размера виджет
void MapView::resizeEvent(QResizeEvent *event)
{
    timer->start(timer_delay);   //как только событие произошло стартуем таймер для отрисовки
    QGraphicsView::resizeEvent(event);  //запускаем событие родителького класса
}

void MapView::mousePressEvent(QMouseEvent *mousePressEvt)
{
    QPointF point = mousePressEvt->pos();
    if (td.joinable()) {
        td.detach();
    }
    int go_x = point.x() + mapScene->sceneRect().topLeft().x();
    int go_y = point.y() + mapScene->sceneRect().topLeft().y();
    td = std::thread(Go, go_x, go_y); //в отдельном потоке запускаем движение

    emit passCoord(point);
}

int MapView::border(int axis, int length, int length_end) {
    int wall = axis - length / 2;
    if (wall < 0) {
        wall = 0;
    }
    if (wall > length_end - length) {
        wall = length_end - length;
    }
    return wall;
}
