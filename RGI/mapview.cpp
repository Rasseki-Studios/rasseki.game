#include "mapview.h"
#include "gamewindow.h"
#include "libAdapter.h"

#include <thread>

using namespace SessionData;
const int offset = 50;

MapView::MapView(QWidget *parent)
    : QGraphicsView(parent)
{
    //настройка отображения виджета и его содержимого
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //отключим скроллбар по горизонтали
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   //отключим скроллбар по вертикали
    //setAlignment(Qt::AlignCenter);                        //делаем привязку содержимого к центру
    //setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    //растягиваем содержимое по виджету

    coord end = EndOfMap();
    width_end = 1000; //end.x;
    height_end = 1000; //end.y;
    qDebug() << width_end << " - - - " << height_end;

    mapScene = new QGraphicsScene(this);   //инициализируем сцену для отрисовки

    QPixmap img(":/resources/img/map.jpg"); //карта
    img.scaled(width(), height(), Qt::KeepAspectRatio);
    mapScene->setBackgroundBrush(QBrush(img));    //устанавливаем Background виджета (изображение карты)

    QPixmap img_h(":/resources/img/hero.png");  //герой
    hero = mapScene->addPixmap(img_h.scaled(100, 100, Qt::KeepAspectRatio));

    coord pos = Coords();   //установливаем положение героя
    qDebug() << pos.x << " | " << pos.y;
    QPoint point(pos.x, pos.y);
    hero->setPos(point);
    int width = this->width();
    int height = this->height();
    int x = pos.x - width / 2;
    int y = pos.y - height / 2;
    if (x < 0) {
        x = 0;
    }
    if (x > width_end - width) {
        x = width_end - width;
    }
    if (y < 0) {
        y = 0;
    }
    if (y > height_end - height) {
        y = height_end - height;
    }
    mapScene->setSceneRect(x, y, width, height);

    setScene(mapScene); //устанавливаем сцену в виджет

    //необходимо некоторое время, чтобы родительский слой развернулся, чтобы принимать от него адекватные параметры ширины и высоты
    timer = new QTimer();   //инициализируем Таймер
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));    //подключаем СЛОТ для отрисовки к таймеру
    timer->start(50);   //стартуем таймер на 50 миллисекунд
}

MapView::~MapView()
{
    if (td.joinable()) {
        td.join();
    }
    delete mapScene;
//    delete hero;
    delete timer;
}

void MapView::slotAlarmTimer()
{
    //mapScene->setSceneRect(0, 0, width, height);    //устанавливаем размер сцены по размеру виджета

    coord pos = Coords();   //устанавливаем героя на актуальную позицию
    QPoint point(pos.x - offset, pos.y - offset);
    hero->setPos(point);

    int width = this->width();      //определяем ширину нашего виджета
    int height = this->height();    //определяем высоту нашего виджета
    int x = pos.x - width / 2;
    int y = pos.y - height / 2;
    if (x < 0) {
        x = 0;
    }
    if (x > width_end - width) {
        x = width_end - width;
    }
    if (y < 0) {
        y = 0;
    }
    if (y > height_end - height) {
        y = height_end - height;
    }
    mapScene->setSceneRect(x, y, width, height);
}

//этим методом перехватываем событие изменения размера виджет
void MapView::resizeEvent(QResizeEvent *event)
{
    timer->start(50);   //как только событие произошло стартуем таймер для отрисовки
    QGraphicsView::resizeEvent(event);  //запускаем событие родителького класса
}

void MapView::mousePressEvent(QMouseEvent *mousePressEvt)
{
    qDebug() << "Mouse event worked";
    QPointF point = mousePressEvt->pos();
    if (td.joinable()) {
        td.join();
    }
    int go_x = point.x() + mapScene->sceneRect().topLeft().x();
    int go_y = point.y() + mapScene->sceneRect().topLeft().y();
    qDebug() << go_x << " and " << go_y;
    td = std::thread(Go, go_x, go_y); //в отдельном потоке запускаем движение

    emit passCoord(point);
}
