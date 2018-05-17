#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <gamewindow.h>

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = 0);
    ~MenuWindow();

private slots:
    void on_newGame_clicked();

    void on_loadGame_clicked();

    void on_exitGame_clicked();

private:
    Ui::MenuWindow *ui;
    GameWindow *Game;
};

#endif // MENUWINDOW_H
