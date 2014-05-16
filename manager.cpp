#include "manager.h"
#include "parcelle.h"
#include "grille.h"
#include <QApplication>

manager::manager() {

}

int manager::begin(int argc, char *argv[]) {

    QApplication app(argc, argv);

    f = new fenetre();

    QPushButton  * boutonCreerProjet = new QPushButton("Creer un projet");
    QObject::connect(boutonCreerProjet, SIGNAL(clicked()), this, SLOT(newProjet()));
    boutonCreerProjet->move(250, 100);
    f->getCenterPanel()->addWidget(boutonCreerProjet);

    QPushButton * boutonOuvrirProjet = new QPushButton("Ouvrir un projet");
    QObject::connect(boutonOuvrirProjet, SIGNAL(clicked()), this, SLOT(importProject()));
    boutonOuvrirProjet->move(250, 200);
    f->getCenterPanel()->addWidget(boutonOuvrirProjet);
    QPushButton * boutonQuitter = new QPushButton("quitter");
    QObject::connect(boutonQuitter, SIGNAL(clicked()), &app, SLOT(quit()));
    boutonQuitter->move(250, 300);
    f->getCenterPanel()->addWidget(boutonQuitter);

    widthLabel = new QLabel("width");
    widthLabel->move(50, 50);
    f->getTopPanel()->addWidget(widthLabel);

    widthText = new QTextEdit("5");
    widthText->move(100, 50);
    widthText->setFixedSize(50, 30);
    f->getTopPanel()->addWidget(widthText);

    heightLabel = new QLabel("height");
    heightLabel->move(180, 50);
    f->getTopPanel()->addWidget(heightLabel);

    heightText = new QTextEdit("5");
    heightText->move(250, 50);
    heightText->setFixedSize(50, 30);
    f->getTopPanel()->addWidget(heightText);

    valideButton = new QPushButton("valider");
    QObject::connect(valideButton, SIGNAL(clicked()), this, SLOT(createGrille()));
    valideButton->move(350, 50);
    f->getTopPanel()->addWidget(valideButton);

    f->getTopPanel()->setVisible(false);


    QPushButton  * boutonRoute = new QPushButton("route");
    boutonRoute->move(20, 50);
    f->getRightPanel()->addWidget(boutonRoute);

    QPushButton  * boutonSignalisation = new QPushButton("signalisation");
    boutonSignalisation->move(20, 100);
    f->getRightPanel()->addWidget(boutonSignalisation);

    f->show();

    return app.exec();
}

void manager::newProjet() {

    g = new grille();

    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0; j < 5 ; j++) {
            g->addWidget(new parcelle(), i, j);
        }
    }

    f->getCenterPanel()->removeAll();
    f->getCenterPanel()->setLayout(g->getGridLayout());

    f->getTopPanel()->setVisible(true);

}

void manager::createGrille() {
    delete g;

    g = new grille();

    QString stringWidth = widthText->toPlainText();
    int width = stringWidth.toInt();

    QString stringHeight = heightText->toPlainText();
    int height = stringHeight.toInt();

    for (int i = 0 ; i < height ; i++) {
        for (int j = 0; j < width ; j++) {
            g->addWidget(new parcelle(), i, j);
        }
    }

    f->getCenterPanel()->removeAll();
    f->getCenterPanel()->setLayout(g->getGridLayout());

}

void manager::importProject() {

}
