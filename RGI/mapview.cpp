#include "mapview.h"
#include "gamewindow.h"
#include "libAdapter.h"

MapView::MapView(QWidget *parent)
    : QGraphicsView(parent)
{
    //настройка отображения виджета и его содержимого
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //отключим скроллбар по горизонтали
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   //отключим скроллбар по вертикали
    setAlignment(Qt::AlignCenter);                        //делаем привязку содержимого к центру
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    //растягиваем содержимое по виджету

    //растягиваем изображение по размеру объекта
    QPixmap img(":/resources/img/testmap.bmp");
    img.scaled(this->width(), this->height(), Qt::KeepAspectRatio);

    mapScene = new QGraphicsScene();   //инициализируем сцену для отрисовки
    mapScene->setBackgroundBrush(QBrush(img));    //устанавливаем Background виджета (изображение карты)

    setScene(mapScene);          //устанавливаем сцену в виджет

    hero = new QGraphicsItemGroup(); //инициализируем первую группу элементов
    mapScene->addItem(hero);         //добавляем первую группу в сцену

    //необходимо некоторое время, чтобы родительский слой развернулся, чтобы принимать от него адекватные параметры ширины и высоты
    timer = new QTimer();   //инициализируем Таймер
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));    //подключаем СЛОТ для отрисовки к таймеру
    timer->start(50);   //стартуем таймер на 50 миллисекунд
}

MapView::~MapView()
{
    delete mapScene;
    delete hero;
    delete timer;
}

void MapView::slotAlarmTimer()
{
    deleteItemsFromGroup(hero); //удаляем все элементы со сцены, если они есть перед новой отрисовкой

    int width = this->width();      //определяем ширину нашего виджета
    int height = this->height();    //определяем высоту нашего виджета
    mapScene->setSceneRect(0, 0, width, height);    //устанавливаем размер сцены по размеру виджет

    QPixmap img(":/resources/img/hero.png");
    hero->addToGroup(mapScene->addPixmap(img.scaled(100,100,Qt::KeepAspectRatio)));
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
    qDebug() << Go(point.x(), point.y());

    emit passCoord(point);
}
