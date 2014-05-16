#include "pieton.h"
#include <cstring>
#include <string>

Pieton::Pieton()
{
}

Pieton::Pieton(int v, int d, int x, int y)
{
    vitesse = v;
    degrePriseDeRisque = d;
    posx = x;
    posy = y;
}

void Pieton::avancer(std::string mouvement){
    if (strcmp(mouvement.c_str(), "up") == 0) {
        posy++;
    } else if (strcmp(mouvement.c_str(), "down") == 0) {
        posy--;
    } else if (strcmp(mouvement.c_str(), "left") == 0) {
        posx--;
    } else if (strcmp(mouvement.c_str(), "right") == 0) {
        posx++;
    }
}
