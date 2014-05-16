#include "grille.h"

grille::grille() {
    gridLayout = new QGridLayout();
    widgets = new tableauDeuxDimension<QWidget *>(5, 5);
}

grille::grille(QWidget *parent) {
    gridLayout = new QGridLayout(parent);
    widgets = new tableauDeuxDimension<QWidget *>(5, 5);
}

QGridLayout* grille::getGridLayout() {
    return gridLayout;
}

void grille::addWidget(QWidget *widget, int i, int j) {
    gridLayout->addWidget(widget, i, j);
    widgets->addItem(widget, i, j);
}

grille::~grille() {
    delete widgets;
    delete gridLayout;
}
