#-------------------------------------------------
#
# Project created by QtCreator 2014-02-13T19:16:56
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settings.cpp \
    gamewindow.cpp \
    openglwidget.cpp \
    gamemodel.cpp \
    params.cpp \
    building.cpp \
    texture.cpp \
    texture_buffer.cpp \
    select_building_widget.cpp \
    buildings/cityhall.cpp \
    buildings/smallhouse.cpp \
    gamemenu.cpp \
    buildings/factory.cpp \
    buildings/bar.cpp \
    buildings/hospital.cpp \
    buildings/clothing.cpp \
    buildings/store.cpp \
    buildings/leisure.cpp \
    buildings/police.cpp \
    buildings/firehouse.cpp \
    buildings/office.cpp \
    buildings/road.cpp \
    xernyathread.cpp

HEADERS  += mainwindow.h \
    settings.h \
    gamewindow.h \
    openglwidget.h \
    gamemodel.h \
    params.h \
    building.h \
    texture.h \
    texture_buffer.h \
    select_building_widget.h \
    buildings/cityhall.h \
    buildings/smallhouse.h \
    gamemenu.h \
    buildings/factory.h \
    buildings/bar.h \
    buildings/hospital.h \
    buildings/clothing.h \
    buildings/store.h \
    buildings/leisure.h \
    buildings/police.h \
    buildings/firehouse.h \
    buildings/office.h \
    buildings/road.h \
    xernyathread.h

FORMS    += mainwindow.ui \
    settings.ui \
    gamewindow.ui \
    select_building_widget.ui \
    gamemenu.ui

RESOURCES += \
    gameres.qrc

OTHER_FILES += \
    vertex.vert \
    frag.frag \
    vertex2.vert \
    frag2.frag \
    vertex.vert \
    frag.frag
