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
    silveruser.cpp \
    user.cpp \
    userinfo.cpp \
    admininfo.cpp \
    container.cpp \
    admin.cpp \
    database.cpp

HEADERS  += mainwindow.h \
    bronzeuser.h \
    silveruser.h \
    user.h \
    userinfo.h \
    admininfo.h \
    container.h \
    admin.h \
    database.h

FORMS    += mainwindow.ui \
    userinfo.ui \
    admininfo.ui
