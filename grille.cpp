#include "grille.h"

grille::grille() {
    gridLayout = new QGridLayout();
}

grille::grille(QWidget *parent) {
    gridLayout = new QGridLayout(parent);
}

QGridLayout* grille::getGridLayout() {
    return gridLayout;
}
