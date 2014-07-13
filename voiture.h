#ifndef VOITURE_H
#define VOITURE_H

#include "position.h"
#include "vehicule.h"


class Voiture : public Vehicule {

    public:
        Voiture();
        Voiture(Position *);
        ~Voiture();
        Voiture(const Voiture &);
        Voiture & operator=(const Voiture &);

};

#endif // VOITURE_H
