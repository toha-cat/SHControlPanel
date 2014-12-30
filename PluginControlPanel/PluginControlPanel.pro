#-------------------------------------------------
#
# Project created by QtCreator 2014-12-30T00:22:16
#
#-------------------------------------------------

QT       += network sql

QT       -= gui

TARGET = PluginControlPanel
TEMPLATE = lib

DEFINES += PLUGINCONTROLPANEL_LIBRARY

SOURCES += plugincontrolpanel.cpp

HEADERS += plugincontrolpanel.h\
        plugincontrolpanel_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
