#include "pieton.h"

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

void Pieton::avancer(string mouvement){
    switch (mouvement)
    {
    case "up":
        posy++;
      break;
    case "down":
        posy--;
      break;
    case "left":
        posx--;
      break;
    case "right":
        posx++;
      break;
    default:
      break;
    }
}
