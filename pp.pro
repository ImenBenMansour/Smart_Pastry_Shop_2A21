QT       += core gui sql serialport
QT       += network
QT       += multimedia multimediawidgets
QT+= core gui printsupport



CONFIG += console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connexion.cpp \
    main.cpp \
    mainwindow.cpp \
    notification.cpp \
    offres.cpp \
    promotion.cpp \
    reclamation.cpp

HEADERS += \
    arduino.h \
    connexion.h \
    mainwindow.h \
    notification.h \
    offres.h \
    promotion.h \
    reclamation.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
QMAKE_CXXFLAGS += -std=gnu++11
//camera
QMAKE_CXXFLAGS += -std=gnu++14
