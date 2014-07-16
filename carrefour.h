#ifndef CARREFOUR_H
#define CARREFOUR_H

#include <list>
#include <QThread>

#include "grille.h"
#include "objetroute.h"
#include "vehicule.h"
#include "configuration.h"
#include "route.h"

class Carrefour : public QObject {

    Q_OBJECT

    public:
        Carrefour();
        Carrefour(const Carrefour &);
        Carrefour(std::list<Route *> r);
        Carrefour & operator=(const Carrefour &);
        bool hasRoute(Position *);
        Route findRouteByPosition(Position p);
        std::list<Vehicule> findVehiculeByPosition(Position *);
        grille * getGrille();
        void setGrille(grille *);
        void addRoute (Route *);
        void addObjetRoute (Vehicule *);
        void getConfiguration (Position *);
        void play();
        ~Carrefour();

    public slots:
        void valideConfig();
        void annuleConfig();
        void handlePositionChanged(Position * oldPos, Position * newPos);

    private:
        std::list<Route *> routes;
        std::list<Vehicule *> objetRoutes;
        grille * g;
        Configuration * config;

};

class CarrefourThread : public QThread {

    Q_OBJECT

    public:
        CarrefourThread(Carrefour *, Vehicule *);
        void run();

    signals:
        void positionChanged(Position * oldPos, Position * newPos);

    private:
        Carrefour * c;
        Vehicule * v;

};

#endif // CARREFOUR_H
