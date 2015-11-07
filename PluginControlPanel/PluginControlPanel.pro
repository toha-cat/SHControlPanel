#-------------------------------------------------
#
# Project created by QtCreator 2014-12-30T00:22:16
#
#-------------------------------------------------

QT       += network sql

QT       -= gui

TARGET = PluginControlPanel
TEMPLATE = lib

CONFIG += plugin

DEFINES += PLUGINCONTROLPANEL_LIBRARY

SOURCES += plugincontrolpanel.cpp \
    netserver.cpp \
    comtranslator.cpp

HEADERS += plugincontrolpanel.h\
        plugincontrolpanel_global.h \
    netserver.h \
    comtranslator.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
