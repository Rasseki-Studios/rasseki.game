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
    libs/EasyBMP/EasyBMP.cpp \
    creatures/hero.cpp \
    surfaces/mapscanner.cpp \
    surfaces/surface.cpp \
    database/items_data.cpp \
    database/session_data.cpp \
    adapter/mapview.cpp \
    adapter/journal.cpp \
    adapter/libAdapter.cpp \
    basic/movable.cpp \
    basic/located.cpp \
    basic/item.cpp \
    artifacts/artifact.cpp \
    artifacts/artifact_parser.cpp \
    artifacts/artifact_factory.cpp \
    artifacts/storage.cpp \
    actions/action.cpp \
    actions/action_factory.cpp \
    actions/action_parser.cpp \
    events/event.cpp \
    events/event_factory.cpp \
    events/event_parser.cpp \
    windows/menuwindow.cpp \
    windows/savewindow.cpp \
    windows/gamewindow.cpp \
    windows/loadwindow.cpp \
    adapter/artifactlist.cpp

HEADERS += windows/menuwindow.h \
    windows/savewindow.h \
    windows/gamewindow.h \
    windows/loadwindow.h \
    windows/style.h \
    actions/action.h \
    actions/action_factory.h \
    actions/actions_config.h \
    events/event.h \
    events/event_factory.h \
    events/events_config.h \
    basic/matrix.hpp \
    basic/item.h \
    basic/located.h \
    basic/movable.h \
    artifacts/artifact.h \
    artifacts/storage.h \
    artifacts/artifacts_config.h \
    adapter/mapview.h \
    adapter/journal.h \
    adapter/libAdapter.h \
    libs/EasyBMP/EasyBMP.h \
    libs/json.hpp \
    database/items_data.h \
    database/session_data.h \
    surfaces/mapscanner.h \
    surfaces/surface.h \
    creatures/hero.h \
    configs/russian.h \
    configs/paths.h \
    configs/config.h \
    adapter/artifactlist.h

FORMS += windows/menuwindow.ui \
    windows/gamewindow.ui \
    windows/loadwindow.ui \
    windows/savewindow.ui

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
