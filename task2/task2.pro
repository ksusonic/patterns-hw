QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    error.cpp \
    filechoose.cpp \
    main.cpp \
    mainwindow.cpp \
    submit.cpp \
    textinput.cpp

HEADERS += \
    baseWindowbuilder.h \
    error.h \
    filechoose.h \
    mainwindow.h \
    submit.h \
    textinput.h

FORMS += \
    error.ui \
    filechoose.ui \
    mainwindow.ui \
    submit.ui \
    textinput.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
