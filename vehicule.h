#ifndef VEHICULE_H
#define VEHICULE_H

#include <list>
#include <Position.h>

class Vehicule
{
public:
    void avancer();
    void reculer();
    void tournerGauche();
    void tournerDroite();
    Vehicule();
private:
    bool canMove;
    std::list<Position> PositionsPrevisionnelles;
};

#endif // VEHICULE_H
