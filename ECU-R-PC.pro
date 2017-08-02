#-------------------------------------------------
#
# Project created by QtCreator 2017-08-02T20:23:57
#
#-------------------------------------------------

QT       += core gui network

TARGET = ECU-R-PC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Source/socket/Socket.cpp

HEADERS  += mainwindow.h \
    Source/socket/Socket.h

FORMS    += mainwindow.ui
