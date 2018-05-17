/********************************************************************************
** Form generated from reading UI file 'savewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEWINDOW_H
#define UI_SAVEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SaveWindow
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *backSaving;
    QPushButton *saveSaving;
    QListWidget *listWidget;
    QLineEdit *lineEdit;

    void setupUi(QDialog *SaveWindow)
    {
        if (SaveWindow->objectName().isEmpty())
            SaveWindow->setObjectName(QStringLiteral("SaveWindow"));
        SaveWindow->resize(508, 370);
        SaveWindow->setStyleSheet(QLatin1String("QWidget {\n"
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
        gridLayout = new QGridLayout(SaveWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        backSaving = new QPushButton(SaveWindow);
        backSaving->setObjectName(QStringLiteral("backSaving"));

        horizontalLayout_2->addWidget(backSaving);

        saveSaving = new QPushButton(SaveWindow);
        saveSaving->setObjectName(QStringLiteral("saveSaving"));

        horizontalLayout_2->addWidget(saveSaving);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        listWidget = new QListWidget(SaveWindow);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(listWidget, 0, 0, 1, 2);

        lineEdit = new QLineEdit(SaveWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 2);


        retranslateUi(SaveWindow);

        QMetaObject::connectSlotsByName(SaveWindow);
    } // setupUi

    void retranslateUi(QDialog *SaveWindow)
    {
        SaveWindow->setWindowTitle(QApplication::translate("SaveWindow", "Dialog", 0));
        backSaving->setText(QApplication::translate("SaveWindow", "\320\235\320\260\320\267\320\260\320\264", 0));
        saveSaving->setText(QApplication::translate("SaveWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class SaveWindow: public Ui_SaveWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEWINDOW_H
