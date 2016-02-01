QT += qml quick

TEMPLATE = app

TARGET = SHPanel

CONFIG += c++11

SOURCES += main.cpp \
    client.cpp \
    comtranslator.cpp \
    deviceitem.cpp \
    deviceman.cpp \
    app.cpp \
    uibackend.cpp \
    categoryitem.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    client.h \
    comtranslator.h \
    deviceitem.h \
    deviceman.h \
    containers.h \
    app.h \
    uibackend.h \
    protocol.h \
    categoryitem.h

