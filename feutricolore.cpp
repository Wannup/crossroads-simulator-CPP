#include "Feutricolore.h"

FeuTricolore::FeuTricolore() {

}

FeuTricolore::FeuTricolore(const FeuTricolore & feu) {

}

FeuTricolore & FeuTricolore::operator= (const FeuTricolore & feu) {

}

FeuTricolore::~FeuTricolore() {

}

FeuTricolore::FeuTricolore(bool _state, int _frequency) {
    state = _state;
    frequencyChange = _frequency;
}
