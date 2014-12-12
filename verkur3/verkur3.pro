#-------------------------------------------------
#
# Project created by QtCreator 2014-12-11T15:17:00
#
#-------------------------------------------------

QT       += core gui

QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = verkur3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    comparer.cpp \
    computer.cpp \
    database.cpp \
    person.cpp \
    relation.cpp \
    repository.cpp \
    service.cpp \
    utilities.cpp

HEADERS  += mainwindow.h \
    comparer.h \
    computer.h \
    database.h \
    person.h \
    relation.h \
    repository.h \
    service.h \
    utilities.h

FORMS    += mainwindow.ui
