TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    basicuser.cpp \
    admin.cpp \
    container.cpp \
    database.cpp \
    message.cpp \
    messagesdatabase.cpp \
    prouser.cpp \
    user.cpp \
    mainwindow.cpp \
    admininfo.cpp \
    userinfo.cpp

HEADERS += \
    basicuser.h \
    admin.h \
    container.h \
    database.h \
    message.h \
    messagesdatabase.h \
    prouser.h \
    user.h \
    mainwindow.h \
    admininfo.h \
    userinfo.h

FORMS += \
    mainwindow.ui \
    admininfo.ui \
    userinfo.ui

