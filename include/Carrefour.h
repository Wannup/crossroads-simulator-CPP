#ifndef CARREFOUR_H
#define CARREFOUR_H


class Carrefour
{
    public:
        Route findRouteByPosition(Position p);
        Carrefour();
        Carrefour(list<Route> r);
        virtual ~Carrefour();
    protected:
    private:
        list<Route> routes;
};

#endif // CARREFOUR_H
