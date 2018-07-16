#-------------------------------------------------
#
# Project created by QtCreator 2018-05-12T10:56:33
#
#-------------------------------------------------

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rasseki_game
TEMPLATE = app
CONFIG += static

SOURCES = $$files(*.cpp, true)
HEADERS = $$files(*.h, true)
FORMS = $$files(*.ui, true)

INCLUDEPATH += windows \
    actions \
    events \
    artifacts \
    basic \
    adapter \
    database \
    surfaces \
    creatures \
    configs

RESOURCES += resources/resource.qrc

unix:LIBS += -lstdc++fs

QMAKE_CXXFLAGS += -g

DESTDIR = $$PWD

OBJECTS_DIR = $$PWD/temp/.obj
MOC_DIR = $$PWD/temp/.moc
RCC_DIR = $$PWD/temp/.rcc
UI_DIR = $$PWD/temp/.ui
