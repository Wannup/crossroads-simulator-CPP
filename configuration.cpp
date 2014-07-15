#include "configuration.h"

Configuration::Configuration() {

}

Configuration::Configuration(const Configuration & config) {

}

Configuration & Configuration::operator= (const Configuration & config) {

}

Configuration::~Configuration() {

}

Vehicule * Configuration::getVehicule() {
    return this->vehicule;
}

void Configuration::setVehicule(Vehicule * vehicule) {
    this->vehicule = vehicule;
}

void Configuration::setRoute(Route * route) {
    this->route = route;
}

void Configuration::setPosition(Position * pos) {
    this->pos = pos;
}

QWidget * Configuration::getQWidget() {
    return this->configWidget;
}

void Configuration::setQWidget(QWidget * widget) {
    this->configWidget = widget;
}

QTextEdit * Configuration::getXTextEdit() {
    return this->xTextEdit;
}

QTextEdit * Configuration::getYTextEdit() {
    return this->yTextEdit;
}

void Configuration::setXTextEdit(QTextEdit * textEdit) {
    this->xTextEdit = textEdit;
}

void Configuration::setYTextEdit(QTextEdit * textEdit) {
    this->yTextEdit = textEdit;
}
