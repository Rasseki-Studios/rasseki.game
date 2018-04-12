#ifndef MAPFIELD_H
#define MAPFIELD_H

#include <QWidget>

class MapField : public QWidget
{
    Q_OBJECT
public:
    explicit MapField(QWidget *parent = nullptr);

protected:
    void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // MAPFIELD_H
