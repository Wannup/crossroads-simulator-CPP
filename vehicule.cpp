#include "vehicule.h"

Vehicule::Vehicule() : ObjetRoute::ObjetRoute() {

}

Vehicule::Vehicule(const Vehicule & vehicule) : ObjetRoute::ObjetRoute(vehicule) {
    this->position = vehicule.position;
    this->positionArrivee = vehicule.positionArrivee;
}

Vehicule & Vehicule::operator= (const Vehicule & vehicule) {
    ObjetRoute::operator =(vehicule);
    this->position = vehicule.position;
    this->positionArrivee = vehicule.positionArrivee;
    return *this;
}

Vehicule::~Vehicule() {

}

Vehicule::Vehicule(Position * pos) {
    position = pos;
}

Position * Vehicule::getPosition() {
    return this->position;
}

Position * Vehicule::getPositionArrivee() {
    return this->positionArrivee;
}

void Vehicule::setPositionArrivee(Position * pos) {
    this->positionArrivee = pos;
}

std::string Vehicule::getType() {
    return "vehicule";
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

bool Vehicule::estArrivee()  {
    return *(this->position) == *(this->positionArrivee);
}

