#ifndef POSITION_H
#define POSITION_H

#include <Contrainte.h>
#include <list>

class Position
{
public:
    Position();
private:
    int x;
    int y;
    bool isFree;
    std::list<Position> positionsConnexes;
//    std::list<Contrainte> contraintes;
};

#endif // POSITION_H
