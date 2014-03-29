#ifndef CARREFOUR_H
#define CARREFOUR_H

#include <Route.h>
#include <list>

class Carrefour
{
public:
    Route findRouteByPosition(Position p);
    Carrefour();
    Carrefour(std::list<Route> r);
private:
    std::list<Route> routes;
};

#endif // CARREFOUR_H
