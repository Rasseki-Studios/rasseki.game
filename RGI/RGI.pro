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
    savewindow.cpp \
    journal.cpp

HEADERS  += menuwindow.h \
    gamewindow.h \
    loadwindow.h \
    mapview.h \
    savewindow.h \
    journal.h

FORMS    += menuwindow.ui \
    gamewindow.ui \
    loadwindow.ui \
    savewindow.ui

RESOURCES += \
    resource.qrc

CONFIG += C++17
QMAKE_CXXFLAGS += -std=c++17 -pthread -lstdc++fs
QMAKE_CXX = g++

#Добавление статической библиотеки (адаптер)
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../release/ -lAdapter -lstdc++fs
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../debug/ -lAdapter -lstdc++fs
else:unix: LIBS += -L$$PWD/../ -lAdapter -lstdc++fs

INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../release/libAdapter.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../debug/libAdapter.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../release/Adapter.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../debug/Adapter.lib
else:unix: PRE_TARGETDEPS += $$PWD/../libAdapter.a
