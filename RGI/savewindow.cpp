#include "savewindow.h"
#include "ui_savewindow.h"

SaveWindow::SaveWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveWindow)
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

SaveWindow::~SaveWindow()
{
    delete ui;
}

void SaveWindow::on_backSaving_clicked()
{   //закрыть окно сохранения игры
    close();
}
