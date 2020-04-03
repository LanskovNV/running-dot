TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#SOURCES +=
QT += gl
LIBS += /usr/lib/libglut.so /usr/lib/libGL.so

SOURCES += \
    ./src/main.cpp \
    ./src/point_class.cpp \
    ./src/queue_class.cpp \
    ./src/timer_class.cpp

HEADERS += \
    ./src/color_class.h \
    ./src/point_class.h \
    ./src/queue_class.h \
    ./src/timer_class.h
