#include "savewindow.h"
#include "ui_savewindow.h"

#include "paths.h"
#include "style.h"

SaveWindow::SaveWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveWindow)
{
    ui->setupUi(this);

    //установка фона и размеров окна загрузки игры
    QImage bg_window(img_bground.c_str());
    setFixedSize(width(), height());
    QBrush br;
    br.setTextureImage(bg_window);
    QPalette plt = palette();
    plt.setBrush(QPalette::Background, br);
    setPalette(plt);

    //установка стилей
    this->setStyleSheet((css_widget + css_pushbutton + css_messagebox).c_str());
}

SaveWindow::~SaveWindow()
{
    delete ui;
}

void SaveWindow::on_backSaving_clicked()
{   //закрыть окно сохранения игры
    close();
}
