#-------------------------------------------------
#
# Project created by QtCreator 2015-12-27T18:22:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BankQ
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bronzeuser.cpp \
    golduser.cpp \
    silveruser.cpp \
    user.cpp \
    userinfo.cpp \
    admininfo.cpp

HEADERS  += mainwindow.h \
    bronzeuser.h \
    golduser.h \
    silveruser.h \
    user.h \
    userinfo.h \
    admininfo.h

FORMS    += mainwindow.ui \
    userinfo.ui \
    admininfo.ui
