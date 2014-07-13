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
        ~Position();
        Position(int, int);
        void avancer();
        void reculer();
        void droite();
        void gauche();
        int getPositionX();
        int getPositionY();

    private:
        int x;
        int y;
        bool isFree;
        std::list<Position> positionsConnexes;
        //std::list<Contrainte> contraintes;
};

#endif // POSITION_H
