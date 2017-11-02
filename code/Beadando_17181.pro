TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lpthread

SOURCES += main.cpp \
    taskperformerinterface.cpp \
    speedtester.cpp \
    fibonacci.cpp \
    logreader.cpp

HEADERS += \
    taskperformerinterface.h \
    speedtester.h \
    fibonacci.h \
    logreader.h
