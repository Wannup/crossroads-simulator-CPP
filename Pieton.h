#ifndef PIETON_H
#define PIETON_H

class Pieton
{
public:
    Pieton();
    Pieton(int vitesse, int degrePriseDeRisque, int posx, int posy);
    void avancer();
private:
    int vitesse;
    int degrePriseDeRisque;
    int posx;
    int posy;
};

#endif // PIETON_H
