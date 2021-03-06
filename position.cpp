#include "position.h"

Position::Position() {
    this->x = 0;
    this->y = 0;
}

Position::Position(int i, int j) {
    this->x = i;
    this->y = j;
}

Position::Position(int i, int j, orientation ori) {
    this->x = i;
    this->y = j;
    this->orienta = ori;
}

Position::Position(const Position & position) {
    this->x = position.x;
    this->y = position.y;
    this->orienta = position.orienta;

}

Position & Position::operator= (const Position & position) {
    if (this == &position) {
        return *this;
    }
    this->x = position.x;
    this->y = position.y;
    this->orienta = position.orienta;
    return *this;
}

bool Position::operator==(const Position & position) {
    return this->x == position.x && this->y == position.y;
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

orientation Position::getOrientation() {
    return this->orienta;
}
