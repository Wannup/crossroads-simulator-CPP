#ifndef CARREFOUR_H
#define CARREFOUR_H

#include <Route.h>
#include <list>

#include "grille.h"
#include "objetroute.h"
#include "vehicule.h"
#include "configuration.h"

class Carrefour : public QObject {

    Q_OBJECT

    public:
        Carrefour();
        Carrefour(const Carrefour &);
        Carrefour(std::list<Route> r);
        Carrefour & operator=(const Carrefour &);
        Route findRouteByPosition(Position p);
        std::list<Vehicule> findVehiculeByPosition(Position *);
        grille * getGrille();
        void addObjetRoute (Vehicule *);
        void getConfiguration (Position *);
        void play();
        ~Carrefour();

    public slots:
        void valideConfig();
        void annuleConfig();

    private:
        std::list<Route> routes;
        std::list<Vehicule> objetRoutes;
        grille * g;
        Configuration * config;

};

#endif // CARREFOUR_H
