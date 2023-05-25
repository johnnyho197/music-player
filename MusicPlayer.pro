QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clib_ma.cpp \
    iplayer.cpp \
    isong.cpp \
    main.cpp \
    mainwindow.cpp
    clib_ma.cpp
    isong.cpp
    iplayer.cpp

HEADERS += \
    clib_ma.h \
    iplayer.h \
    isong.h \
    mainwindow.h \
    miniaudio.h
    clib_ma.h
    isong.h
    iplayer.h
    miniaudio.h

FORMS += \
    mainwindow.ui


TRANSLATIONS += \
    MusicPlayer_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix|win32: LIBS += -L$$PWD/taglib/bin -ltag

INCLUDEPATH += $$PWD/taglib/include
DEPENDPATH += $$PWD/taglib/include
