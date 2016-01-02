QT += qml quick

TEMPLATE = app

TARGET = SHPanel

CONFIG += c++11

SOURCES += main.cpp \
    client.cpp \
    comtranslator.cpp \
    devicelisst.cpp \
    window.cpp \
    deviceitem.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    client.h \
    comtranslator.h \
    devicelisst.h \
    window.h \
    deviceitem.h

