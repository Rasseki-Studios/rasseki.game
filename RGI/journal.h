#ifndef JOURNAL_H
#define JOURNAL_H

#include <QTextEdit>
#include <QTimer>

#include <memory>

class Journal : public QTextEdit
{
    Q_OBJECT
public:
    explicit Journal(QWidget *parent = 0);

public slots:
    void slotWrite();

private:
    std::shared_ptr<QTimer> timer;

};

#endif // JOURNAL_H
