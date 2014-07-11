#ifndef FEUTRICOLORE_H
#define FEUTRICOLORE_H

#include "objetroute.h"

class FeuTricolore : public ObjetRoute {

    public:
        FeuTricolore();
        FeuTricolore(bool state, int frequencyChange);

    private:
        bool state;     // false -> red - true -> green
        int frequencyChange;

};

#endif // FEUTRICOLORE_H
