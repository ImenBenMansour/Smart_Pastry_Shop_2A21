QT       += sql core gui charts sql printsupport network
QT       +=serialport
QT       +=core gui multimedia multimediawidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connexion.cpp \
    crud_equipement.cpp \
    crud_menu.cpp \
    crud_recette.cpp \
    gestion_equipement.cpp \
    gestion_menu.cpp \
    gestion_recette.cpp \
    main.cpp \
    mainwindow.cpp \
    statistics.cpp \
    video_play.cpp

HEADERS += \
    arduino.h \
    connexion.h \
    crud_equipement.h \
    crud_menu.h \
    crud_recette.h \
    gestion_equipement.h \
    gestion_menu.h \
    gestion_recette.h \
    mainwindow.h \
    statistics.h \
    video_play.h

FORMS += \
    gestion_equipement.ui \
    gestion_menu.ui \
    gestion_recette.ui \
    mainwindow.ui \
    statistics.ui \
    video_play.ui

QMAKE_CXXFLAGS +=  -std=gnu++11

TRANSLATIONS += \
    cuisine_fr_BE.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
