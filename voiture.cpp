#include "Voiture.h"

Voiture::Voiture() {

}

Voiture::Voiture(Position * pos):Vehicule(pos) {

}

Voiture::Voiture(const Voiture & voiture):Vehicule(voiture) {

}

Voiture & Voiture::operator= (const Voiture & voiture) {
    Vehicule::operator =(voiture);
    return *this;
}

Voiture::~Voiture() {

}

std::string Voiture::getType() {
    return "voiture";
}
