#include "loadwindow.h"
#include "ui_loadwindow.h"

#include "paths.h"

LoadWindow::LoadWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadWindow)
{
    ui->setupUi(this);

    //установка фона и размеров окна загрузки игры
    QImage bg_window(img_bground);
    setFixedSize(width(), height());
    QBrush br;
    br.setTextureImage(bg_window);
    QPalette plt = palette();
    plt.setBrush(QPalette::Background, br);
    setPalette(plt);
}

LoadWindow::~LoadWindow()
{
    delete ui;
}

void LoadWindow::on_loadLoading_2_clicked()
{

}

void LoadWindow::on_backLoading_2_clicked()
{   //закрыть окно загрузки игры
    close();
}
