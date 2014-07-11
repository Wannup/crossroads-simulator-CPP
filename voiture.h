#ifndef VOITURE_H
#define VOITURE_H

#include "position.h"
#include "vehicule.h"


class Voiture : public Vehicule {

    public:
        Voiture();
        Voiture(Position *);

};

#endif // VOITURE_H
