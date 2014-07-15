#ifndef ROUTE_H
#define ROUTE_H

#include <list>
#include "position.h"

class Route {

    public:
        Route();
        Route(Position *);
        Route(const Route &);
        Route & operator=(const Route &);
        ~Route();
        Position * getPosition();
        std::list<Position> positionsDepartPossible();
        std::list<Position> positionsArriveePossible();
        std::list<Position> positionsIntersection();

    private:
        Position * pos;

};

#endif // ROUTE_H
