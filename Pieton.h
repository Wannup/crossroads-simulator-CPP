#ifndef PIETON_H
#define PIETON_H

#include "objetroute.h"

#include <string>

class Pieton : public ObjetRoute {

    public:
        Pieton();
        Pieton(const Pieton &);
        ~Pieton();
        Pieton & operator=(const Pieton &);
        Pieton(int vitesse, int degrePriseDeRisque, int posx, int posy);
        void avancer(std::string mouvement);
    private:
        int vitesse;
        int degrePriseDeRisque;
        int posx;
        int posy;
};

#endif // PIETON_H
