TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bronzeuser.cpp \
    silveruser.cpp \
    user.cpp \
    golduser.cpp

HEADERS += \
    bronzeuser.h \
    silveruser.h \
    user.h \
    golduser.h

