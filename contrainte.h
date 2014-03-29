#ifndef CONTRAINTE_H
#define CONTRAINTE_H

#include <list>
#include <Position.h>

class Contrainte
{
public:
    std::list<Position> positionsApplicationContrainte();
    Contrainte();
private:
    bool isApplicable;
};

#endif // CONTRAINTE_H
