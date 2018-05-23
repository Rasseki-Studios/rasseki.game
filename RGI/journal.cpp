#include "journal.h"

#include "libAdapter.h"

#include <QDebug>

Journal::Journal(QWidget *parent) : QTextEdit(parent)
{
    qDebug() << "hi";
    //connect(this, &Journal::passLogBookEntry, this, &Journal::append);

    timer = new QTimer();   //инициализируем Таймер
    connect(timer, SIGNAL(timeout()), this, SLOT(slotWrite()));    //подключаем СЛОТ для отрисовки к таймеру
    timer->start(50);   //стартуем таймер на 50 миллисекунд
}

Journal::~Journal()
{
    delete timer;
}

void Journal::slotWrite() {
    std::string message, writer;
    writer = Write(&message);
    if (message != "") {
        writer += ": ";
        writer += message;
        append(writer.c_str());
    }
}
