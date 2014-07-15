#ifndef VEHICULE_H
#define VEHICULE_H

#include "objetroute.h"
#include "position.h"

#include <list>
#include <string>

class Vehicule : public ObjetRoute {

    public:
        Vehicule();
        Vehicule(const Vehicule &);
        Vehicule & operator=(const Vehicule &);
        ~Vehicule();
        Vehicule(Position *);
        Position * getPosition();
        Position * getPositionArrivee();
        void setPositionArrivee(Position *);
        virtual std::string getType();
        void avancer();
        void reculer();
        void tournerGauche();
        void tournerDroite();
        bool estArrivee();

    private:
        Position * position;
        Position * positionArrivee;
        bool canMove;
        std::list<Position> PositionsPrevisionnelles;
};

#endif // VEHICULE_H
