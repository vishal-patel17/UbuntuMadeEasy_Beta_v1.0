#-------------------------------------------------
#
# Project created by QtCreator 2015-05-19T11:49:56
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form.cpp \
    newform.cpp

HEADERS  += mainwindow.h \
    form.h \
    newform.h

FORMS    += mainwindow.ui \
    form.ui \
    newform.ui
