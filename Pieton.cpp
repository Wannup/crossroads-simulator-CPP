#include "pieton.h"
#include <cstring>
#include <string>

Pieton::Pieton() {

}

Pieton::Pieton(const Pieton &p) {

}

Pieton::Pieton(int v, int d, int x, int y) {
    vitesse = v;
    degrePriseDeRisque = d;
    posx = x;
    posy = y;
}

Pieton & Pieton::operator=(const Pieton & p) {

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

Pieton::~Pieton() {

}
