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

    coord end = EndOfMap();
    width_end = end.x;
    height_end = end.y;

    mapScene = new QGraphicsScene(this);   //инициализируем сцену для отрисовки

    QPixmap img_m(img_map); //карта
    img_m.scaled(width(), height(), Qt::KeepAspectRatio);
    mapScene->setBackgroundBrush(QBrush(img_m));    //устанавливаем Background виджета (изображение карты)

    QPixmap img_h(img_hero);  //герой
    hero = mapScene->addPixmap(img_h.scaled(100, 100, Qt::KeepAspectRatio));

    coord pos = Coords();   //установливаем положение героя
    QPoint point(pos.x, pos.y);
    hero->setPos(point);
    int width = this->width();
    int height = this->height();

    int x = (pos.x, width, width_end);
    int y = (pos.y, height, height_end);
    mapScene->setSceneRect(x, y, width, height);

    setScene(mapScene); //устанавливаем сцену в виджет

    //необходимо некоторое время, чтобы родительский слой развернулся, чтобы принимать от него адекватные параметры ширины и высоты
    timer = new QTimer();   //инициализируем Таймер
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));    //подключаем слот для отрисовки к таймеру
    timer->start(timer_delay);   //стартуем таймер
}

MapView::~MapView()
{
    if (td.joinable()) {
        td.join();
    }
    delete mapScene;
    delete hero;
    delete timer;
}

void MapView::slotAlarmTimer()
{
    coord pos = Coords();   //устанавливаем героя на актуальную позицию
    QPoint point(pos.x - hero_offset, pos.y - hero_offset);
    hero->setPos(point);

    int width = this->width();      //определяем ширину нашего виджета
    int height = this->height();    //определяем высоту нашего виджета

    int x = (pos.x, width, width_end);
    int y = (pos.y, height, height_end);
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
        td.join();
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
