QT       += core gui sql
QT+= core gui printsupport
QT += charts
QT       += core gui network
QT += network
CONFIG += console
QT       += multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    cartefid.cpp \
    chat.cpp \
    clientfid.cpp \
    commande.cpp \
    connexion.cpp \
    crud_equipement.cpp \
    crud_menu.cpp \
    crud_recette.cpp \
    employe.cpp \
    fournisseurs.cpp \
    main.cpp \
    mainwindow.cpp \
    notification.cpp \
    poste.cpp \
    produits.cpp \
    promotion.cpp \
    reclamation.cpp \
    reservation.cpp \
    smtp.cpp \
    statistics.cpp

HEADERS += \
    arduino.h \
    cartefid.h \
    chat.h \
    clientfid.h \
    commande.h \
    connexion.h \
    crud_equipement.h \
    crud_menu.h \
    crud_recette.h \
    employe.h \
    fournisseurs.h \
    mainwindow.h \
    notification.h \
    poste.h \
    produits.h \
    promotion.h \
    reclamation.h \
    reservation.h \
    smtp.h \
    statistics.h

FORMS += \
    chat.ui \
    mainwindow.ui \
    statistics.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

