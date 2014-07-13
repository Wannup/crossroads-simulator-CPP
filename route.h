#ifndef ROUTE_H
#define ROUTE_H

#include <list>
#include <Position.h>

class Route {

    public:
        Route();
        Route(const Route &);
        Route & operator=(const Route &);
        ~Route();
        std::list<Position> positionsDepartPossible();
        std::list<Position> positionsArriveePossible();
        std::list<Position> positionsIntersection();

};

#endif // ROUTE_H
