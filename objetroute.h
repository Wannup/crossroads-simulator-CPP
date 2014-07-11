#ifndef OBJETROUTE_H
#define OBJETROUTE_H

#include "configuration.h"

class ObjetRoute {

    public:
        ObjetRoute();
        ObjetRoute(Configuration *);
        void play();

    private:
        Configuration * config;

};

#endif // OBJETROUTE_H
