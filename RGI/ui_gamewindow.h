/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <journal.h>
#include "mapview.h"

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    MapView *map;
    QHBoxLayout *horizontalLayout;
    QPushButton *exit;
    QGridLayout *gridLayout;
    QLabel *logoHero;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *level;
    QLabel *speed;
    QLabel *nameHero;
    Journal *book;

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
        map = new MapView(centralwidget);
        map->setObjectName(QStringLiteral("map"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(map->sizePolicy().hasHeightForWidth());
        map->setSizePolicy(sizePolicy);
        map->setMinimumSize(QSize(500, 500));

        gridLayout_2->addWidget(map, 0, 0, 3, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        exit = new QPushButton(centralwidget);
        exit->setObjectName(QStringLiteral("exit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(exit->sizePolicy().hasHeightForWidth());
        exit->setSizePolicy(sizePolicy1);
        exit->setMinimumSize(QSize(50, 50));
        exit->setMaximumSize(QSize(16777215, 16777215));
        exit->setAutoDefault(true);

        horizontalLayout->addWidget(exit);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        logoHero = new QLabel(centralwidget);
        logoHero->setObjectName(QStringLiteral("logoHero"));
        logoHero->setMinimumSize(QSize(120, 120));
        logoHero->setMaximumSize(QSize(120, 120));
        logoHero->setPixmap(QPixmap(QString::fromUtf8(":/resources/img/hero.png")));

        gridLayout->addWidget(logoHero, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 81, 17));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 81, 17));
        level = new QLabel(groupBox);
        level->setObjectName(QStringLiteral("level"));
        level->setGeometry(QRect(90, 60, 67, 17));
        speed = new QLabel(groupBox);
        speed->setObjectName(QStringLiteral("speed"));
        speed->setGeometry(QRect(90, 80, 67, 17));
        nameHero = new QLabel(groupBox);
        nameHero->setObjectName(QStringLiteral("nameHero"));
        nameHero->setGeometry(QRect(10, 20, 120, 17));
        nameHero->setStyleSheet(QStringLiteral("text-align: center"));

        gridLayout->addWidget(groupBox, 0, 1, 2, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        book = new Journal(centralwidget);
        book->setObjectName(QStringLiteral("book"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(book->sizePolicy().hasHeightForWidth());
        book->setSizePolicy(sizePolicy2);
        book->setMinimumSize(QSize(350, 0));
        book->setMaximumSize(QSize(440, 16777215));
        book->setStyleSheet(QStringLiteral("color: black"));

        gridLayout_2->addWidget(book, 2, 1, 1, 1);

        GameWindow->setCentralWidget(centralwidget);

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "MainWindow", 0));
        exit->setText(QApplication::translate("GameWindow", "\320\222\321\213\321\205\320\276\320\264", 0));
        logoHero->setText(QString());
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("GameWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214:", 0));
        label_2->setText(QApplication::translate("GameWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214:", 0));
        level->setText(QApplication::translate("GameWindow", "0", 0));
        speed->setText(QApplication::translate("GameWindow", "0", 0));
        nameHero->setText(QApplication::translate("GameWindow", "<html><head/><body><p>\320\230\320\274\321\217</p></body></html>", 0));
        book->setHtml(QApplication::translate("GameWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
