TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt
QT += widgets

SOURCES += main.cpp \
    Carrefour.cpp \
    Contrainte.cpp \
    FenPrincipale.cpp \
    Feutricolore.cpp \
    Position.cpp \
    Route.cpp \
    Vehicule.cpp \
    Voiture.cpp

HEADERS += \
    Carrefour.h \
    Contrainte.h \
    FenPrincipale.h \
    Feutricolore.h \
    Position.h \
    Route.h \
    Voiture.h \
    Vehicule.h

FORMS +=

