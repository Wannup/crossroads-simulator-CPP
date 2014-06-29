#include "manager.h"
#include "parcelle.h"
#include "grille.h"
#include <QApplication>
#include <QTreeWidget>

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

    widthText = new QTextEdit("10");
    widthText->move(100, 50);
    widthText->setFixedSize(50, 30);
    f->getTopPanel()->addWidget(widthText);

    heightLabel = new QLabel("height");
    heightLabel->move(180, 50);
    f->getTopPanel()->addWidget(heightLabel);

    heightText = new QTextEdit("10");
    heightText->move(250, 50);
    heightText->setFixedSize(50, 30);
    f->getTopPanel()->addWidget(heightText);

    valideButton = new QPushButton("valider");
    QObject::connect(valideButton, SIGNAL(clicked()), this, SLOT(createGrille()));
    valideButton->move(350, 50);
    f->getTopPanel()->addWidget(valideButton);

    playButton = new QPushButton("play");
    QObject::connect(playButton, SIGNAL(clicked()), this, SLOT(play()));
    playButton->move(450, 50);
    f->getTopPanel()->addWidget(playButton);

    pauseButton = new QPushButton("pause");
    QObject::connect(pauseButton, SIGNAL(clicked()), this, SLOT(pause()));
    pauseButton->move(550, 50);
    f->getTopPanel()->addWidget(pauseButton);

    stopButton = new QPushButton("stop");
    QObject::connect(stopButton, SIGNAL(clicked()), this, SLOT(stop()));
    stopButton->move(650, 50);
    f->getTopPanel()->addWidget(stopButton);

    saveButton = new QPushButton("save");
    QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
    saveButton->move(750, 50);
    f->getTopPanel()->addWidget(saveButton);

    f->getTopPanel()->setVisible(false);

    QTreeWidget * treeWidget = new QTreeWidget();
    f->getRightPanel()->addWidget(treeWidget);
    QTreeWidgetItem * treeWidgetItem = new QTreeWidgetItem(treeWidget);

    QPushButton  * boutonRoute = new QPushButton("route");
    boutonRoute->move(20, 50);
    f->getRightPanel()->addWidget(boutonRoute);

    QPushButton  * boutonSignalisation = new QPushButton("signalisation");
    boutonSignalisation->move(20, 100);
    f->getRightPanel()->addWidget(boutonSignalisation);

    f->getRightPanel()->setVisible(false);

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

    this->createGrille();

    f->getTopPanel()->setVisible(true);
    f->getRightPanel()->setVisible(true);

    playButton->setDisabled(false);
    pauseButton->setDisabled((true));
    stopButton->setDisabled((true));
    saveButton->setDisabled(false);

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

void manager::play() {
    valideButton->setDisabled(true);
    playButton->setDisabled(true);
    pauseButton->setDisabled(false);
    stopButton->setDisabled(false);
    saveButton->setDisabled(true);
}

void manager::pause() {
    valideButton->setDisabled(false);
    playButton->setDisabled(false);
    pauseButton->setDisabled((true));
    stopButton->setDisabled((true));
    saveButton->setDisabled(false);
}

void manager::stop() {
    valideButton->setDisabled(false);
    playButton->setDisabled(false);
    pauseButton->setDisabled((true));
    stopButton->setDisabled((true));
    saveButton->setDisabled(false);
}

void manager::save() {

}
