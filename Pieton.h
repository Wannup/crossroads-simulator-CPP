#ifndef PIETON_H
#define PIETON_H

#include <string>

class Pieton
{
public:
    Pieton();
    Pieton(int vitesse, int degrePriseDeRisque, int posx, int posy);
    void avancer(std::string mouvement);
private:
    int vitesse;
    int degrePriseDeRisque;
    int posx;
    int posy;
};

#endif // PIETON_H
