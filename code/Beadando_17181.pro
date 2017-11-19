TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lpthread

SOURCES += main.cpp \
    taskperformerinterface.cpp \
    speedtester.cpp \
    fibonacci.cpp \
    logreader.cpp \
    fibonacciperformer.cpp \
    speedtesterperformer.cpp \
    logreaderperformer.cpp \
    taskcontainer.cpp \
    worker.cpp \
    taskobserver.cpp

HEADERS += \
    taskperformerinterface.h \
    speedtester.h \
    fibonacci.h \
    logreader.h \
    fibonacciperformer.h \
    speedtesterperformer.h \
    logreaderperformer.h \
    taskcontainer.h \
    worker.h \
    taskobserver.h
