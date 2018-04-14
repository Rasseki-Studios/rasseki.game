#include "mapfield.h"
#include <QDebug>
#include <QPoint>
#include <QMouseEvent>

MapField::MapField(QWidget *parent) : QWidget(parent)
{
}

void MapField::mouseReleaseEvent(QMouseEvent *e) {
    qDebug() << "Mouse event worked";
    QPoint point = e->pos();

    qDebug() << point.x() << " and " << point.y();
}
