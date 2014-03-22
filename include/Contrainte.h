#ifndef CONTRAINTE_H
#define CONTRAINTE_H


class Contrainte
{
    public:
        list<Position> positionsApplicationContrainte();
        Contrainte();
        virtual ~Contrainte();
    protected:
    private:
        bool isApplicable;

};

#endif // CONTRAINTE_H
