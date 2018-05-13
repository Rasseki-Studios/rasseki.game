#include "loadwindow.h"
#include "ui_loadwindow.h"

LoadWindow::LoadWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadWindow)
{
    ui->setupUi(this);

    //установка фона и размеров окна меню
    setFixedSize(width(), height());
    QImage bg_window(":/resources/img/bground.png");
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

void LoadWindow::on_backLoading_clicked()
{   //закрытие окна загрузки игры
    close();
}
