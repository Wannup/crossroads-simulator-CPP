#include "Position.h"

Position::Position() {
    this->x = 0;
    this->y = 0;
}

Position::Position(int i, int j) {
    this->x = i;
    this->y = j;
}

Position::Position(const Position & position) {
    this->x = position.x;
    this->y = position.y;

}

Position & Position::operator= (const Position & position) {
    if (this == &position) {
        return *this;
    }
    this->x = position.x;
    this->y = position.y;
    return *this;
}

Position::~Position() {

}

void Position::avancer() {
    this->y++;
}

void Position::reculer () {
    this->y--;
}

void Position::droite() {
    this->x++;
}

void Position::gauche() {
    this->x--;
}

int Position::getPositionX() {
    return this->x;
}

int Position::getPositionY() {
    return this->y;
}
