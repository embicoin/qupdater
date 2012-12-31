TEMPLATE = app


TARGET = tst_qupdater
STATICLINK = 0
PROJECTROOT = $$PWD/..
include($$PROJECTROOT/src/libQUpdater.pri)
preparePaths($$OUT_PWD/../out)

#win32:LIBS += -lUser32

SOURCES += main.cpp
HEADERS += 


