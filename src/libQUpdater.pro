TEMPLATE = lib

QT += core gui network 
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG *= qupdater-buildlib
#var with '_' can not pass to pri?
STATICLINK = 0
PROJECTROOT = $$PWD/..
!include(libQUpdater.pri): error(could not find libQUpdater.pri)
preparePaths($$OUT_PWD/../out)

#src
unix: SOURCES += 
else:win32: SOURCES += 

SOURCES += QUpdater.cpp

HEADERS += QUpdater_Global.h QUpdater.h



