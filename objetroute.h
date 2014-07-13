#ifndef OBJETROUTE_H
#define OBJETROUTE_H

#include "configuration.h"

class ObjetRoute {

    public:
        ObjetRoute();
        ObjetRoute(const ObjetRoute &);
        ObjetRoute & operator=(const ObjetRoute &);
        ~ObjetRoute();
        ObjetRoute(Configuration *);
        void play();

    private:
        Configuration * config;

};

#endif // OBJETROUTE_H
