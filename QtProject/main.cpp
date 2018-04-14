#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QPoint>
#include <QMouseEvent>
#include <QtWidgets>
#include "mapfield.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWind;

    mainWind.show();

    return a.exec();
}

/*bool MapField::event(QMouseEvent *event)
{


    return true;
}



url(./img/map.png)*/
