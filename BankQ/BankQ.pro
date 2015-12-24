TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
#@QT += widgets@



SOURCES += main.cpp \
    bronzeuser.cpp \
    silveruser.cpp \
    user.cpp \
    golduser.cpp \
    window.cpp

HEADERS += \
    bronzeuser.h \
    silveruser.h \
    user.h \
    golduser.h \
    window.h

FORMS += \
    window.ui

