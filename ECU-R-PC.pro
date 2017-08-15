#-------------------------------------------------
#
# Project created by QtCreator 2017-08-02T20:23:57
#
#-------------------------------------------------

QT       += core gui network

RC_FILE = myapp.rc
TARGET = ECU-R-PC
TEMPLATE = app

DESTDIR = $$PWD/Target/XP

SOURCES += main.cpp\
        mainwindow.cpp \
    communication.cpp

HEADERS  += mainwindow.h \
    communication.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    myapp.rc
