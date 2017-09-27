#-------------------------------------------------
#
# Project created by QtCreator 2017-09-25T13:31:19
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PMPLay_WServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myserver.cpp

HEADERS  += mainwindow.h \
    myserver.h

FORMS    += mainwindow.ui
