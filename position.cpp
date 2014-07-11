#include "Position.h"

Position::Position() {

}

Position::Position(int i, int j) {
    this->x = i;
    this->y = j;
}

void Position::avancer() {
    this->x++;
}

void Position::reculer () {
    this->x--;
}

void Position::droite() {
    this->y++;
}

void Position::gauche() {
    this->y--;
}

int Position::getPositionX() {
    return this->x;
}

int Position::getPositionY() {
    return this->y;
}
