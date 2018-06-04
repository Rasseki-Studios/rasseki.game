#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>

#include <thread>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

private slots:
    void on_exit_clicked();

    void on_load_clicked();

    void on_save_clicked();

private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
