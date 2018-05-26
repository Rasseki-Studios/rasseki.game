#-------------------------------------------------
#
# Project created by QtCreator 2018-05-12T10:56:33
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rasseki_game
TEMPLATE = app

SOURCES += main.cpp \
    mapview.cpp \
    journal.cpp \
    libs/EasyBMP/EasyBMP.cpp \
    artifact.cpp \
    artifact_factory.cpp \
    artifact_parser.cpp \
    hero.cpp \
    item.cpp \
    items_data.cpp \
    libAdapter.cpp \
    location.cpp \
    mapscanner.cpp \
    matrix.cpp \
    movable.cpp \
    session_data.cpp \
    storage.cpp \
    surface.cpp \
    events/event.cpp \
    events/event_factory.cpp \
    events/event_parser.cpp \
    windows/menuwindow.cpp \
    windows/savewindow.cpp \
    windows/gamewindow.cpp \
    windows/loadwindow.cpp

HEADERS += windows/menuwindow.h \
    windows/savewindow.h \
    windows/gamewindow.h \
    windows/loadwindow.h \
    events/event.h \
    events/event_factory.h \
    mapview.h \
    journal.h \
    libs/EasyBMP/EasyBMP.h \
    libs/json.hpp \
    artifact.h \
    hero.h \
    item.h \
    items_data.h \
    libAdapter.h \
    location.h \
    mapscanner.h \
    matrix.h \
    movable.h \
    session_data.h \
    storage.h \
    surface.h

FORMS += windows/menuwindow.ui \
    windows/gamewindow.ui \
    windows/loadwindow.ui \
    windows/savewindow.ui

INCLUDEPATH += windows \
    events

RESOURCES += resource.qrc

CONFIG += C++17
QMAKE_CXXFLAGS += -std=c++17 -pthread
QMAKE_CXX = g++

LIBS += -lstdc++fs
