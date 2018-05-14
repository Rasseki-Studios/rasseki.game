#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "loadwindow.h"
#include "savewindow.h"

#include <QMessageBox>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_exit_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Выход", "Вы действительно хотите выйти в главное меню?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        hide();
        parentWidget()->show();
        close();
    }
}

void GameWindow::on_load_clicked()
{   //запуск окна загрузки игры
    LoadWindow Load;
    Load.setModal(true);
    Load.exec();
}

void GameWindow::on_save_clicked()
{   //запуск окна сохранения игры
    SaveWindow Save;
    Save.setModal(true);
    Save.exec();
}
