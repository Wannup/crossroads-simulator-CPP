#include "objetroute.h"

ObjetRoute::ObjetRoute() {

}

ObjetRoute::ObjetRoute(const ObjetRoute & objRoute) {

}

ObjetRoute & ObjetRoute::operator= (const ObjetRoute & objRoute) {
    return *this;
}

ObjetRoute::~ObjetRoute() {

}

ObjetRoute::ObjetRoute(Configuration * c) {
    config = c;
}

void ObjetRoute::play() {

}
