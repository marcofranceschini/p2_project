TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    user.cpp \
    bronzeuser.cpp \
    silveruser.cpp

HEADERS += \
    bronzeuser.h \
    user.h \
    silveruser.h

