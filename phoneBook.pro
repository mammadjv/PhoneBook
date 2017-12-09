TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt
QT += widgets
QT += sql

SOURCES += main.cpp \
    phonebookview.cpp \
    databasemanager.cpp \
    phonebookcontroller.cpp

FORMS += \
    phonebookview.ui

HEADERS += \
    phonebookview.h \
    databasemanager.h \
    phonebookcontroller.h

