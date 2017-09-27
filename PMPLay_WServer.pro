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
    myserver.cpp \
    adminpanelform.cpp \
    pmp_user.cpp \
    pmp_group.cpp

HEADERS  += mainwindow.h \
    myserver.h \
    adminpanelform.h \
    pmp_user.h \
    pmp_genre.h \
    pmp_group.h

FORMS    += mainwindow.ui \
    adminpanelform.ui
