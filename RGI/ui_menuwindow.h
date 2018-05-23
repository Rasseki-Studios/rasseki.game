/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *logo;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QPushButton *newGame;
    QPushButton *loadGame;
    QPushButton *settingGame;
    QPushButton *exitGame;
    QLabel *label_2;

    void setupUi(QMainWindow *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName(QStringLiteral("MenuWindow"));
        MenuWindow->resize(682, 488);
        MenuWindow->setStyleSheet(QLatin1String("QWidget {\n"
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
        centralWidget = new QWidget(MenuWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 90, 565, 385));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(60);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        logo = new QLabel(gridLayoutWidget);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setMinimumSize(QSize(250, 350));
        logo->setPixmap(QPixmap(QString::fromUtf8("img/archer.png")));

        gridLayout->addWidget(logo, 0, 0, 3, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 750));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        newGame = new QPushButton(gridLayoutWidget);
        newGame->setObjectName(QStringLiteral("newGame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newGame->sizePolicy().hasHeightForWidth());
        newGame->setSizePolicy(sizePolicy);
        newGame->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(newGame);

        loadGame = new QPushButton(gridLayoutWidget);
        loadGame->setObjectName(QStringLiteral("loadGame"));
        sizePolicy.setHeightForWidth(loadGame->sizePolicy().hasHeightForWidth());
        loadGame->setSizePolicy(sizePolicy);
        loadGame->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(loadGame);

        settingGame = new QPushButton(gridLayoutWidget);
        settingGame->setObjectName(QStringLiteral("settingGame"));
        sizePolicy.setHeightForWidth(settingGame->sizePolicy().hasHeightForWidth());
        settingGame->setSizePolicy(sizePolicy);
        settingGame->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(settingGame);

        exitGame = new QPushButton(gridLayoutWidget);
        exitGame->setObjectName(QStringLiteral("exitGame"));
        sizePolicy.setHeightForWidth(exitGame->sizePolicy().hasHeightForWidth());
        exitGame->setSizePolicy(sizePolicy);
        exitGame->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(exitGame);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);


        gridLayout->addLayout(verticalLayout, 1, 1, 2, 1);

        MenuWindow->setCentralWidget(centralWidget);
        gridLayoutWidget->raise();

        retranslateUi(MenuWindow);

        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MenuWindow)
    {
        MenuWindow->setWindowTitle(QApplication::translate("MenuWindow", "Rasseki Game", 0));
        logo->setText(QString());
        label->setText(QApplication::translate("MenuWindow", "<html><head/><body><p><br/></p><p><span style=\" font-size:24pt;\">Rasseki Game</span></p></body></html>", 0));
        newGame->setText(QApplication::translate("MenuWindow", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", 0));
        loadGame->setText(QApplication::translate("MenuWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\270\320\263\321\200\321\203", 0));
        settingGame->setText(QApplication::translate("MenuWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0));
        exitGame->setText(QApplication::translate("MenuWindow", "\320\222\321\213\321\205\320\276\320\264", 0));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
