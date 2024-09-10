#-------------------------------------------------
#
# Project created by QtCreator 2024-09-05T20:32:53
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += QT_SQL_MYSQL

TARGET = EnjoyJourney
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    EJDetailWidget.cpp

HEADERS  += mainwindow.h \
    EJDetailWidget.h
