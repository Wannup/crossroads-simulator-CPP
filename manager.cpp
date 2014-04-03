#include "manager.h"
#include "parcelle.h"
#include "grille.h"
#include <QApplication>
#include <QPushButton>

manager::manager() {

}

int manager::begin(int argc, char *argv[]) {

    QApplication app(argc, argv);

    f = new fenetre();

    QPushButton boutonCreerProjet("Creer un projet", f);
    QObject::connect(&boutonCreerProjet, SIGNAL(clicked()), this, SLOT(newProjet()));
    boutonCreerProjet.move(250, 100);
    QPushButton boutonOuvrirProjet("Ouvrir un projet", f);
    QObject::connect(&boutonOuvrirProjet, SIGNAL(clicked()), this, SLOT(importProject()));
    boutonOuvrirProjet.move(250, 200);
    QPushButton boutonQuitter("quitter", f);
    QObject::connect(&boutonQuitter, SIGNAL(clicked()), &app, SLOT(quit()));
    boutonQuitter.move(250, 300);

    f->show();

    return app.exec();
}

void manager::newProjet() {

    g = new grille(f);

    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0; j < 5 ; j++) {
            g->getGridLayout()->addWidget(new parcelle(), i, j);
        }
    }
    QWidget* widget = new QWidget(f);
    widget->setLayout(g->getGridLayout());
    f->setCentralWidget(widget);
}

void manager::importProject() {

}
