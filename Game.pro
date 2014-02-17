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
    building.cpp

HEADERS  += mainwindow.h \
    settings.h \
    gamewindow.h \
    openglwidget.h \
    gamemodel.h \
    params.h \
    building.h

FORMS    += mainwindow.ui \
    settings.ui \
    gamewindow.ui

RESOURCES += \
    gameres.qrc

OTHER_FILES += \
    vertex.vert \
    frag.frag \
    vertex2.vert \
    frag2.frag \
    vertex.vert \
    frag.frag
