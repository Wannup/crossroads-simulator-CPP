#ifndef ROUTE_H
#define ROUTE_H

#include <list>
#include <Position.h>

class Route
{
public:
    std::list<Position> positionsDepartPossible();
    std::list<Position> positionsArriveePossible();
    std::list<Position> positionsIntersection();
    Route();
};

#endif // ROUTE_H
