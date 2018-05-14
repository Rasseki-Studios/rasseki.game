/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "mapview.h"

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    MapView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QPushButton *save;
    QPushButton *load;
    QPushButton *setting;
    QPushButton *exit;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QStringLiteral("GameWindow"));
        GameWindow->resize(874, 600);
        GameWindow->setStyleSheet(QLatin1String("QWidget {\n"
"	color: white;\n"
"	font-weight: bold\n"
"}\n"
"\n"
"QPushButton {\n"
"  color: white;\n"
"  text-decoration: none;\n"
"  padding: .5em 2em;\n"
"  outline: none;\n"
"  border-width: 2px 0;\n"
"  border-style: solid none;\n"
"  border-color: #FDBE33 #000 #D77206;\n"
"  border-radius: 6px;\n"
"  background: linear-gradient(#F3AE0F, #E38916) #E38916;\n"
"}\n"
"\n"
"QMessageBox {\n"
"    background-color: #CD853F;\n"
"	background-image: url(\":/resources/img/bground.png\")\n"
"}"));
        centralwidget = new QWidget(GameWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        graphicsView = new MapView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(500, 500));

        gridLayout_2->addWidget(graphicsView, 0, 0, 3, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        save = new QPushButton(centralwidget);
        save->setObjectName(QStringLiteral("save"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(save->sizePolicy().hasHeightForWidth());
        save->setSizePolicy(sizePolicy1);
        save->setMinimumSize(QSize(50, 50));
        save->setMaximumSize(QSize(105, 16777215));
        save->setAutoDefault(true);

        horizontalLayout->addWidget(save);

        load = new QPushButton(centralwidget);
        load->setObjectName(QStringLiteral("load"));
        sizePolicy1.setHeightForWidth(load->sizePolicy().hasHeightForWidth());
        load->setSizePolicy(sizePolicy1);
        load->setMinimumSize(QSize(50, 50));
        load->setMaximumSize(QSize(105, 16777215));
        load->setAutoDefault(true);

        horizontalLayout->addWidget(load);

        setting = new QPushButton(centralwidget);
        setting->setObjectName(QStringLiteral("setting"));
        sizePolicy1.setHeightForWidth(setting->sizePolicy().hasHeightForWidth());
        setting->setSizePolicy(sizePolicy1);
        setting->setMinimumSize(QSize(50, 50));
        setting->setMaximumSize(QSize(105, 16777215));
        setting->setAutoDefault(true);

        horizontalLayout->addWidget(setting);

        exit = new QPushButton(centralwidget);
        exit->setObjectName(QStringLiteral("exit"));
        sizePolicy1.setHeightForWidth(exit->sizePolicy().hasHeightForWidth());
        exit->setSizePolicy(sizePolicy1);
        exit->setMinimumSize(QSize(50, 50));
        exit->setMaximumSize(QSize(105, 16777215));
        exit->setAutoDefault(true);

        horizontalLayout->addWidget(exit);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy2);
        textEdit->setMinimumSize(QSize(350, 0));
        textEdit->setMaximumSize(QSize(440, 16777215));

        gridLayout_2->addWidget(textEdit, 2, 1, 1, 1);

        GameWindow->setCentralWidget(centralwidget);

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "MainWindow", 0));
        save->setText(QApplication::translate("GameWindow", "PushButton", 0));
        load->setText(QApplication::translate("GameWindow", "PushButton", 0));
        setting->setText(QApplication::translate("GameWindow", "PushButton", 0));
        exit->setText(QApplication::translate("GameWindow", "PushButton", 0));
        label_2->setText(QApplication::translate("GameWindow", "TextLabel", 0));
        label->setText(QApplication::translate("GameWindow", "\320\223\320\265\321\200\320\276\320\271", 0));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
