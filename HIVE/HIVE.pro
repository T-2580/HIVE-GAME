QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ai.cpp \
    anothergamewindow.cpp \
    gameboard.cpp \
    gamewindow.cpp \
    hexbutton.cpp \
    main.cpp \
    mainwindow.cpp \
    piece.cpp\
    singlegamewindow.cpp

HEADERS += \
    ai.h \
    anothergamewindow.h \
    gameboard.h \
    gamewindow.h \
    hexbutton.h \
    mainwindow.h \
    piece.h\
    singlegamewindow.h

FORMS += \
    mainwindow.ui \
    gamewindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
