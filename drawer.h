#ifndef DRAWER_H
#define DRAWER_H

#include <QWidget>
#include <string>

enum routeType {
    route_horizontal,
    route_vertical,
    croisement,
    feu_tricolor,
    panneau_stop,
    voiture,
    moto,
    camion,
    pieton
};

class drawer {

    public:
        drawer();
        drawer(routeType type);
        drawer(std::string type);
        void drawInWidget(QWidget *widget);
        std::string getStringRouteType ();

     private:
        routeType rt;
};

#endif // DRAWER_H
