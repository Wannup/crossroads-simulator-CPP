#ifndef CONTRAINTE_H
#define CONTRAINTE_H

#include <Position.h>
#include <list>

class Contrainte {

    public:
        Contrainte();
        Contrainte(const Contrainte &);
        Contrainte & operator=(const Contrainte &);
        ~Contrainte();

    private:
        bool isApplicable;
        //std::list<Position> positionsPrevisionnelles;
};

#endif // CONTRAINTE_H
