#-------------------------------------------------
#
# Project created by QtCreator 2018-05-12T10:56:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RGI
TEMPLATE = app


SOURCES += main.cpp\
        menuwindow.cpp \
    gamewindow.cpp \
    loadwindow.cpp \
    mapview.cpp \
    savewindow.cpp

HEADERS  += menuwindow.h \
    gamewindow.h \
    loadwindow.h \
    mapview.h \
    savewindow.h

FORMS    += menuwindow.ui \
    gamewindow.ui \
    loadwindow.ui \
    savewindow.ui

RESOURCES += \
    resource.qrc
