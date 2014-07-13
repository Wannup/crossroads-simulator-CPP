#ifndef CARREFOUR_H
#define CARREFOUR_H

#include <Route.h>
#include <list>

#include "grille.h"
#include "objetroute.h"

class Carrefour {

    public:
        Carrefour();
        Carrefour(const Carrefour &);
        Carrefour(std::list<Route> r);
        Carrefour & operator=(const Carrefour &);
        Route findRouteByPosition(Position p);
        grille * getGrille();
        void addObjetRoute (ObjetRoute *);
        void play();
        ~Carrefour();

    private:
        std::list<Route> routes;
        std::list<ObjetRoute> objetRoutes;
        grille * g;

};

#endif // CARREFOUR_H
