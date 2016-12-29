#-------------------------------------------------
#
# Project created by QtCreator 2016-12-28T11:11:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DLLDemo2
TEMPLATE = app

LIBS+= -lHBStreamSDK

SOURCES += main.cpp\
        dlldemo2.cpp

HEADERS  += dlldemo2.h

FORMS    += dlldemo2.ui
