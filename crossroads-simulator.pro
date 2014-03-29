TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    carrefour.cpp \
    contrainte.cpp \
    feutricolore.cpp \
    position.cpp \
    route.cpp \
    vehicule.cpp \
    voiture.cpp \
    mainwindow.cpp

HEADERS += \
    carrefour.h \
    contrainte.h \
    feutricolore.h \
    position.h \
    route.h \
    vehicule.h \
    voiture.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

