#ifndef VEHICULE_H
#define VEHICULE_H

#include <list>

class Vehicule
{
public:
    avancer();
    reculer();
    tournerGauche();
    tournerDroite();
    Vehicule();
private:
    bool canMove;
    std::List<Position> PositionsPrevisionnelles;
};

#endif // VEHICULE_H
