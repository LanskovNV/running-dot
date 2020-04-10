TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#SOURCES +=
QT += gl
LIBS += /usr/lib/libglut.so /usr/lib/libGL.so

SOURCES += \
    src/main.cpp \
    src/point.cpp \
    src/track.cpp

HEADERS += \
    src/point.h \
    src/track.h
