#ifndef POSITION_H
#define POSITION_H

#include <list>
#include <Contrainte.h>

class Position
{
public:
    Position();
private:
    int x;
    int y;
    bool isFree;
    std::List<Position> positionsConnexes;
    std::List<Contrainte> contraintes;
};

#endif // POSITION_H
