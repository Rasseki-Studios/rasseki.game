#include "loadwindow.h"
#include "ui_loadwindow.h"

LoadWindow::LoadWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadWindow)
{
    ui->setupUi(this);

    //установка фона и размеров окна загрузки игры
    QImage bg_window(":/resources/img/bground.png");
    setFixedSize(width(), height());
    QBrush br;
    br.setTextureImage(bg_window);
    QPalette plt = palette();
    plt.setBrush(QPalette::Background, br);
    setPalette(plt);

    ui->listWidget->addItem("save1");
    ui->listWidget->addItem("save2");
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
