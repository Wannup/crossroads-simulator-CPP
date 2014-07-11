#ifndef VEHICULE_H
#define VEHICULE_H

#include "objetroute.h"
#include "position.h"

#include <list>

class Vehicule : public ObjetRoute {

    public:
        Vehicule();
        Vehicule(Position *);
        Position * getPosition();
        void avancer();
        void reculer();
        void tournerGauche();
        void tournerDroite();

    private:
        Position * position;
        bool canMove;
        std::list<Position> PositionsPrevisionnelles;
};

#endif // VEHICULE_H
