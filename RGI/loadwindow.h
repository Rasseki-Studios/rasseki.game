#ifndef LOADWINDOW_H
#define LOADWINDOW_H

#include <QDialog>

namespace Ui {
class LoadWindow;
}

class LoadWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoadWindow(QWidget *parent = 0);
    ~LoadWindow();

private slots:
    void on_backLoading_clicked();

private:
    Ui::LoadWindow *ui;
};

#endif // LOADWINDOW_H
