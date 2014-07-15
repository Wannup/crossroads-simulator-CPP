#ifndef POSITION_H
#define POSITION_H

#include "contrainte.h"

#include <list>

enum orientation {
    horizontal,
    vertical,
    nord,
    sud,
    est,
    ouest,
    all
};

class Position {

    public:
        Position();
        Position(const Position &);
        Position & operator=(const Position &);
        bool operator==(const Position &);
        ~Position();
        Position(int, int);
        Position(int, int, orientation);
        void avancer();
        void reculer();
        void droite();
        void gauche();
        int getPositionX();
        int getPositionY();
        orientation getOrientation();

    private:
        int x;
        int y;
        bool isFree;
        std::list<Position> positionsConnexes;
        orientation orienta;
        //std::list<Contrainte> contraintes;
};

#endif // POSITION_H
