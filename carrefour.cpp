#include "Carrefour.h"
#include <list>

Carrefour::Carrefour()
{
}

Carrefour::Carrefour(std::list<Route> r)
{
    routes = r;
}

Route Carrefour::findRouteByPosition(Position p)
{

}
