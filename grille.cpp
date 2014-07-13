#include "grille.h"
#include <vector>

grille::grille() {
    gridLayout = new QGridLayout();
    widgets = new tableauDeuxDimension<QWidget *>(5, 5);
}

grille::grille(const grille & g) {

}

grille & grille::operator= (const grille & g) {

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

QWidget * grille::getWidget(int i, int j) {
    return widgets->getItem(i,j);
}

std::vector<QWidget *> grille::getAdjacentWidget(int i, int j) {
    std::vector<QWidget *> vec;
    if (i > 0 && j > 0 && i < widgets->getHeight() && j < widgets->getWidth()) {
        if (i > 0) {
            vec.push_back(widgets->getItem(i-1,j));
        }
        if (j < widgets->getWidth()) {
            vec.push_back(widgets->getItem(i,j+1));
        }
        if (i < widgets->getHeight()) {
            vec.push_back(widgets->getItem(i+1,j));
        }
        if (j > 0) {
            vec.push_back(widgets->getItem(i,j-1));
        }
    }
    return vec;
}

int grille::getWidth() {
    return this->widgets->getWidth();
}

int grille::getHeight() {
    return this->widgets->getHeight();
}

grille::~grille() {
    delete widgets;
    delete gridLayout;
}
