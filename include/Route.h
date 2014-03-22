#ifndef ROUTE_H
#define ROUTE_H


class Route
{
    public:
        list<Position> positionsDepartPossible();
        list<Position> positionsArriveePossible();
        list<Position> positionsIntersection();
        Route();
        virtual ~Route();
    protected:
    private:
};

#endif // ROUTE_H
