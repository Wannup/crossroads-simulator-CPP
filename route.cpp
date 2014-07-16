#include "Route.h"

Route::Route() {

}

Route::Route(Position * position) {
    this->pos = position;
}

Route::Route(const Route & route) {
    this->pos = route.pos;
}

Route & Route::operator= (const Route & route) {
    this->pos = route.pos;
}

Route::~Route() {

}

Position * Route::getPosition() {
    return this->pos;
}
