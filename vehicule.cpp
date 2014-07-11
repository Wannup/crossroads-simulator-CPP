#include "vehicule.h"

Vehicule::Vehicule(){

}

Vehicule::Vehicule(Position * pos) {
    position = pos;
}

Position * Vehicule::getPosition() {
    return this->position;
}

void Vehicule::avancer(){
    this->position->avancer();
}

void Vehicule::reculer(){
    this->position->reculer();
}

void Vehicule::tournerGauche(){
    this->position->gauche();
}

void Vehicule::tournerDroite(){
    this->position->droite();
}
