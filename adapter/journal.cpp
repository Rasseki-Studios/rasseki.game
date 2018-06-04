#include "journal.h"

#include "libAdapter.h"

#include <QDebug>

Journal::Journal(QWidget *parent) : QTextEdit(parent)
{
    //connect(this, &Journal::passLogBookEntry, this, &Journal::append);

    timer = new QTimer();   //инициализируем Таймер
    //подключаем СЛОТ для отрисовки к таймеру
    connect(timer, SIGNAL(timeout()), this, SLOT(slotWrite()));
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
