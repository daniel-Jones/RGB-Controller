#-------------------------------------------------
#
# Project created by QtCreator 2016-03-07T11:25:55
#
#-------------------------------------------------

QT       += core gui serialport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RGBController
TEMPLATE = app


SOURCES += main.cpp\
        controllerwindow.cpp \
    serial_communication.cpp

HEADERS  += controllerwindow.h \
    serial_communication.h

FORMS    += controllerwindow.ui
