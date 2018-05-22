#include "mapview.h"
#include "gamewindow.h"
#include "libAdapter.h"

#include <thread>

const int offset = 50;

MapView::MapView(QWidget *parent)
    : QGraphicsView(parent)
{
    //настройка отображения виджета и его содержимого
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //отключим скроллбар по горизонтали
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   //отключим скроллбар по вертикали
    setAlignment(Qt::AlignCenter);                        //делаем привязку содержимого к центру
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    //растягиваем содержимое по виджету

    mapScene = new QGraphicsScene(this);   //инициализируем сцену для отрисовки

    QPixmap img(":/resources/img/map.jpg"); //карта
    img.scaled(width(), height(), Qt::KeepAspectRatio);
    mapScene->setSceneRect(0, 0, width(), height());
    mapScene->setBackgroundBrush(QBrush(img));    //устанавливаем Background виджета (изображение карты)

    QPixmap img_h(":/resources/img/hero.png");  //герой
    hero = mapScene->addPixmap(img_h.scaled(100, 100, Qt::KeepAspectRatio));

    coord pos = Coords();   //установливаем положение героя
    qDebug() << pos.x << " | " << pos.y;
    QPoint point(pos.x, pos.y);
    hero->setPos(point);

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
    delete hero;
    delete timer;
}

void MapView::slotAlarmTimer()
{
    int width = this->width();      //определяем ширину нашего виджета
    int height = this->height();    //определяем высоту нашего виджета
    mapScene->setSceneRect(0, 0, width, height);    //устанавливаем размер сцены по размеру виджета

    coord pos = Coords();   //устанавливаем героя на актуальную позицию
    QPoint point(pos.x - offset, pos.y - offset);
    hero->setPos(point);
}

//этим методом перехватываем событие изменения размера виджет
void MapView::resizeEvent(QResizeEvent *event)
{
    timer->start(50);   //как только событие произошло стартуем таймер для отрисовки
    QGraphicsView::resizeEvent(event);  //запускаем событие родителького класса
}

//метод для удаления всех элементов из группы
void MapView::deleteItemsFromGroup(QGraphicsItemGroup *group)
{
    foreach(QGraphicsItem *item, mapScene->items(group->boundingRect())) {  //перебираем все элементы сцены
       if(item->group() == group ) {    //если они принадлежат группе, удаляем
          delete item;
       }
    }
}

void MapView::mousePressEvent(QMouseEvent *mousePressEvt)
{
    qDebug() << "Mouse event worked";
    QPointF point = mousePressEvt->pos();
    qDebug() << point.x() << " and " << point.y();
    if (td.joinable()) {
        td.join();
    }
    td = std::thread(Go, point.x(), point.y()); //в отдельном потоке запускаем движение

    emit passCoord(point);
}
