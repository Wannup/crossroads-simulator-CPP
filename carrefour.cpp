#include "carrefour.h"
#include "parcelle.h"
#include "voiture.h"
#include <list>

Carrefour::Carrefour() {
    g = new grille();
}

Carrefour::Carrefour(const Carrefour & carf) {
    this->g = carf.g;
    this->objetRoutes = carf.objetRoutes;
    this->routes = carf.routes;
}

Carrefour::Carrefour(std::list<Route> r) {
    routes = r;
}

Carrefour & Carrefour::operator=(const Carrefour & carf) {
    if (this == &carf) {
        return *this;
    }
    this->g = carf.g;
    this->objetRoutes = carf.objetRoutes;
    this->routes = carf.routes;
    return *this;
}

Route Carrefour::findRouteByPosition(Position p) {

}

grille * Carrefour::getGrille () {
    return this->g;
}

void Carrefour::addObjetRoute(ObjetRoute * objRoute) {
    this->objetRoutes.push_back(*objRoute);
}

void Carrefour::play() {
    std::list<ObjetRoute>::iterator it;
    for (it = this->objetRoutes.begin() ; it != this->objetRoutes.end() ; it++) {
        ObjetRoute objr = (ObjetRoute) *it;
        Voiture * v = (Voiture *) &objr;
        Position * p = v->getPosition();
        parcelle * parc = (parcelle *) this->g->getWidget(0, 0);
        parc->removeVoiture();
        v->avancer();
        parcelle * parc2 = (parcelle *) this->g->getWidget(0, 1);
        parc2->addVoiture();
    }
}

Carrefour::~Carrefour() {
    delete this->g;
}

