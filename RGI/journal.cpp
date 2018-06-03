#include "journal.h"

#include "libAdapter.h"
#include "game_settings.h"
#include "style.h"
#include <QDebug>

Journal::Journal(QWidget *parent) : QTextEdit(parent)
{
    this->setStyleSheet(css_journal);
    timer = new QTimer();   //инициализируем Таймер
    connect(timer, SIGNAL(timeout()), this, SLOT(slotWrite()));    //подключаем cлот для отрисовки к таймеру
    timer->start(timer_delay);   //стартуем таймер
}

void Journal::slotWrite() {
    Message post = Write();
    if (post.text != "") {
        append(post.writer.c_str() + ": " + post.text.c_str());
    }
}
