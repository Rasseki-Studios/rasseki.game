#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "loadwindow.h"
#include "savewindow.h"

#include <QMessageBox>
#include "libAdapter.h"
#include "russian.h"
#include "paths.h"
#include "style.h"

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
    QImage bg_window(img_bground.c_str());
    QBrush br;
    br.setTextureImage(bg_window);
    QPalette plt = palette();
    plt.setBrush(QPalette::Background, br);
    setPalette(plt);

    QPixmap hero(img_hero.c_str());
    int width = ui->logoHero->width();
    int height = ui->logoHero->height();
    ui->logoHero->setPixmap(hero.scaled(width, height, Qt::KeepAspectRatio));

    //установка стилей
    this->setStyleSheet((css_widget + css_pushbutton + css_messagebox + css_list + css_journal).c_str());

    HeroData data = HData();
    ui->nameHero->setText(data.name.c_str());
    ui->level->setText(std::to_string(data.level).c_str());
    ui->speed->setText(std::to_string(data.speed).c_str());
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_exit_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, game_exit.c_str(), is_exit.c_str(), QMessageBox::Yes | QMessageBox::No);
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
