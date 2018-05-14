/********************************************************************************
** Form generated from reading UI file 'loadwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADWINDOW_H
#define UI_LOADWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoadWindow
{
public:
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *backLoading_2;
    QPushButton *loadLoading_2;

    void setupUi(QDialog *LoadWindow)
    {
        if (LoadWindow->objectName().isEmpty())
            LoadWindow->setObjectName(QStringLiteral("LoadWindow"));
        LoadWindow->resize(508, 349);
        LoadWindow->setStyleSheet(QLatin1String("QWidget {\n"
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
        gridLayout = new QGridLayout(LoadWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listWidget = new QListWidget(LoadWindow);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(listWidget, 0, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        backLoading_2 = new QPushButton(LoadWindow);
        backLoading_2->setObjectName(QStringLiteral("backLoading_2"));

        horizontalLayout_2->addWidget(backLoading_2);

        loadLoading_2 = new QPushButton(LoadWindow);
        loadLoading_2->setObjectName(QStringLiteral("loadLoading_2"));

        horizontalLayout_2->addWidget(loadLoading_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 1, 1, 1);


        retranslateUi(LoadWindow);

        QMetaObject::connectSlotsByName(LoadWindow);
    } // setupUi

    void retranslateUi(QDialog *LoadWindow)
    {
        LoadWindow->setWindowTitle(QApplication::translate("LoadWindow", "Dialog", 0));
        backLoading_2->setText(QApplication::translate("LoadWindow", "\320\235\320\260\320\267\320\260\320\264", 0));
        loadLoading_2->setText(QApplication::translate("LoadWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class LoadWindow: public Ui_LoadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADWINDOW_H
