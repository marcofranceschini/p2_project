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
    user.cpp \
    userinfo.cpp \
    admininfo.cpp \
    container.cpp \
    admin.cpp \
    database.cpp \
    message.cpp \
    messagesdatabase.cpp \
    basicuser.cpp \
    prouser.cpp

HEADERS  += mainwindow.h \
    user.h \
    userinfo.h \
    admininfo.h \
    container.h \
    admin.h \
    database.h \
    message.h \
    messagesdatabase.h \
    basicuser.h \
    prouser.h

FORMS    += mainwindow.ui \
    userinfo.ui \
    admininfo.ui
