#-------------------------------------------------
#
# Project created by QtCreator 2016-04-23T10:33:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = painqt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    solarobject.cpp \
    solarsystem.cpp \
    solarsysteminitializer.cpp \
    rocket.cpp \
    planet.cpp

HEADERS  += mainwindow.h \
    solarobject.h \
    solarsystem.h \
    solarsysteminitializer.h \
    rocket.h \
    planet.h

FORMS    += mainwindow.ui
