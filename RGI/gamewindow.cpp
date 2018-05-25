#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "loadwindow.h"
#include "savewindow.h"

#include <QMessageBox>
#include "libAdapter.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    Game();

    Coord max = EndOfMap();
    ui->map->setMaximumWidth(max.x);
    ui->map->setMaximumHeight(max.y);

    //установка фона и размеров окна загрузки игры
    QImage bg_window(":/resources/img/bground.png");
    QBrush br;
    br.setTextureImage(bg_window);
    QPalette plt = palette();
    plt.setBrush(QPalette::Background, br);
    setPalette(plt);

    QPixmap hero(":/resources/img/hero.png");
    int width = ui->logoHero->width();
    int height = ui->logoHero->height();
    ui->logoHero->setPixmap(hero.scaled(width, height, Qt::KeepAspectRatio));

    std::vector<std::string> data;
    data = Data();
    ui->nameHero->setText(data[0].c_str());
    ui->level->setText(data[1].c_str());
    ui->speed->setText(data[2].c_str());
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
