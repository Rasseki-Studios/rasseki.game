#include "mapview.h"
#include "gamewindow.h"

MapView::MapView(QWidget *parent)
    : QGraphicsView(parent)
{
    //настройка отображения виджета и его содержимого
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   //отключим скроллбар по вертикали
    this->setAlignment(Qt::AlignCenter);                        //делаем привязку содержимого к центру
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    //растягиваем содержимое по виджету

    mapScene = new QGraphicsScene();   //инициализируем сцену для отрисовки
    mapScene->setBackgroundBrush(QBrush(QPixmap(":/resources/img/testmap.bmp")));    //устанавливаем Background виджета (изодражение карты)

    this->setScene(mapScene);          //устанавливаем сцену в виджет

    group_1 = new QGraphicsItemGroup(); //инициализируем первую группу элементов
    group_2 = new QGraphicsItemGroup(); //инициализируем вторую группу элементов

    mapScene->addItem(group_1);            //добавляем первую группу в сцену
    mapScene->addItem(group_2);            //добавляем вторую группу в сцену

    //необходимо некоторое время, чтобы родительский слой развернулся, чтобы принимать от него адекватные параметры ширины и высоты
    timer = new QTimer();   //инициализируем Таймер
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));    //подключаем СЛОТ для отрисовки к таймеру
    timer->start(50);   //стартуем таймер на 50 миллисекунд
}

MapView::~MapView()
{
    delete mapScene;
    delete group_1;
    delete group_2;
    delete timer;
}

void MapView::slotAlarmTimer()
{
    //удаляем все элементы со сцены, если они есть перед новой отрисовкой
    this->deleteItemsFromGroup(group_1);
    this->deleteItemsFromGroup(group_2);

    int width = this->width();      //определяем ширину нашего виджета
    int height = this->height();    //определяем высоту нашего виджета
    mapScene->setSceneRect(0, 0, width, height);    //устанавливаем размер сцены по размеру виджета

    //приступаем к отрисовке произвольной картинки
    QPen penBlack(Qt::black); //задаём чёрную кисть
    QPen penRed(Qt::red);   //задаём красную кисть

    //нарисуем черный прямоугольник
    group_1->addToGroup(mapScene->addLine(20,20, width - 20, 20, penBlack));
    group_1->addToGroup(mapScene->addLine(width - 20, 20, width - 20, height -20, penBlack));
    group_1->addToGroup(mapScene->addLine(width - 20, height -20, 20, height -20, penBlack));
    group_1->addToGroup(mapScene->addLine(20, height -20, 20, 20, penBlack));

    //нарисуем красный квадрат
    int sideOfSquare = (height > width) ? (width - 60) : (height - 60);
    int centerOfWidget_X = width/2;
    int centerOfWidget_Y = height/2;

    group_2->addToGroup(mapScene->addLine(centerOfWidget_X - (sideOfSquare/2),
                                       centerOfWidget_Y - (sideOfSquare/2),
                                       centerOfWidget_X + (sideOfSquare/2),
                                       centerOfWidget_Y - (sideOfSquare/2),
                                       penRed));

    group_2->addToGroup(mapScene->addLine(centerOfWidget_X + (sideOfSquare/2),
                                       centerOfWidget_Y - (sideOfSquare/2),
                                       centerOfWidget_X + (sideOfSquare/2),
                                       centerOfWidget_Y + (sideOfSquare/2),
                                       penRed));

    group_2->addToGroup(mapScene->addLine(centerOfWidget_X + (sideOfSquare/2),
                                       centerOfWidget_Y + (sideOfSquare/2),
                                       centerOfWidget_X - (sideOfSquare/2),
                                       centerOfWidget_Y + (sideOfSquare/2),
                                       penRed));

    group_2->addToGroup(mapScene->addLine(centerOfWidget_X - (sideOfSquare/2),
                                       centerOfWidget_Y + (sideOfSquare/2),
                                       centerOfWidget_X - (sideOfSquare/2),
                                       centerOfWidget_Y - (sideOfSquare/2),
                                       penRed));
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

    emit passCoord(point);
}
