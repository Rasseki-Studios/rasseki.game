#ifndef JOURNAL_H
#define JOURNAL_H

#include <QTextEdit>
#include <QTimer>

class Journal : public QTextEdit
{
    Q_OBJECT
public:
    explicit Journal(QWidget *parent = 0);
    ~Journal();

public slots:
    void slotWrite();

private:
    QTimer *timer;

};

#endif // JOURNAL_H
