#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MapField *mf = new MapField(this);
    LogBook *lb = new LogBook(this);

    connect(mf, &MapField::sendNewLine, lb, &LogBook::printNewLine);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
    qDebug() << "x = " << w.x();
    qDebug() << "y = " << w.y();
    qDebug() << "height = " << w.height();
    qDebug() << "width = " << w.width();
    QPoint pos = w.mapToGlobal(QPoint(0,0));
    qDebug() << "x = " << pos.rx();
    qDebug() << "y = " << pos.ry();
    qDebug() << "x = " << pos.x();
    qDebug() << "y = " << pos.y();
*/