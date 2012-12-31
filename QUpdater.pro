TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS = depends libqupdater test

libqupdater.file = src/libQUpdater.pro
test.file = test/tst_QUpdater.pro
test.depends += depends libqupdater

OTHER_FILES += README


