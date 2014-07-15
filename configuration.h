#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "vehicule.h"
#include "route.h"
#include <QTextEdit>

class Configuration {

    public:
        Configuration();
        Configuration(const Configuration &);
        Configuration & operator=(const Configuration &);
        ~Configuration();
        Vehicule * getVehicule();
        void setVehicule (Vehicule *);
        void setRoute(Route *);
        void setPosition (Position *);
        QWidget * getQWidget();
        void setQWidget (QWidget *);
        QTextEdit * getXTextEdit();
        void setXTextEdit (QTextEdit *);
        QTextEdit * getYTextEdit();
        void setYTextEdit (QTextEdit *);

    private:
        Vehicule * vehicule;
        Route * route;
        Position * pos;
        QWidget * configWidget;
        QTextEdit * xTextEdit;
        QTextEdit * yTextEdit;

};

#endif // CONFIGURATION_H
