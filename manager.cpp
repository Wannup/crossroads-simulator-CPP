#include "manager.h"
#include "parcelle.h"
#include "grille.h"
#include "drawer.h"
#include "drawablewidget.h"
#include <QApplication>
#include <QTreeWidget>
#include <QFileDialog>
#include <fstream>
#include <QFileInfo>
#include <QMessageBox>

manager::manager() {

}

int manager::begin(int argc, char *argv[]) {

    QApplication app(argc, argv);

    f = new fenetre();

    QMenuBar *menu = new QMenuBar(f);
    QMenu* menu1 = new QMenu("Fichier");

    QAction  * boutonCreerProjet = new QAction("Creer un projet", f);
    QAction * boutonOuvrirProjet = new QAction("Ouvrir un projet", f);
    QAction * boutonQuitter = new QAction("Quitter", f);

    menu1->addAction(boutonCreerProjet);
    menu1->addAction(boutonOuvrirProjet);
    menu1->addAction(boutonQuitter);

    QObject::connect(boutonQuitter, SIGNAL(triggered()), &app, SLOT(quit()));
    QObject::connect(boutonOuvrirProjet, SIGNAL(triggered()), this, SLOT(loadFromXml()));
    QObject::connect(boutonCreerProjet, SIGNAL(triggered()), this, SLOT(newProjet()));

    menu->addMenu(menu1);

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
    QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(saveToXml()));
    saveButton->move(750, 50);
    f->getTopPanel()->addWidget(saveButton);

    f->getTopPanel()->setVisible(false);

    DrawableWidget drawableWidgetRouteHorizontal(new drawer(route_horizontal));
    drawableWidgetRouteHorizontal.move(20, 100);
    drawableWidgetRouteHorizontal.setFixedSize(40, 40);
    drawableWidgetRouteHorizontal.setAcceptDrops(false);
    f->getRightPanel()->addWidget(&drawableWidgetRouteHorizontal);

    DrawableWidget drawableWidgetRouteVertical(new drawer(route_vertical));
    drawableWidgetRouteVertical.move(20, 150);
    drawableWidgetRouteVertical.setFixedSize(40, 40);
    drawableWidgetRouteVertical.setAcceptDrops(false);
    f->getRightPanel()->addWidget(&drawableWidgetRouteVertical);

    DrawableWidget drawableWidgetCroisement(new drawer(croisement));
    drawableWidgetCroisement.move(20, 200);
    drawableWidgetCroisement.setFixedSize(40, 40);
    drawableWidgetCroisement.setAcceptDrops(false);
    f->getRightPanel()->addWidget(&drawableWidgetCroisement);

    DrawableWidget drawableWidgetFeuTricolor(new drawer(feu_tricolor));
    drawableWidgetFeuTricolor.move(20, 250);
    drawableWidgetFeuTricolor.setFixedSize(40, 40);
    drawableWidgetFeuTricolor.setAcceptDrops(false);
    f->getRightPanel()->addWidget(&drawableWidgetFeuTricolor);

    DrawableWidget drawableWidgetStop(new drawer(panneau_stop));
    drawableWidgetStop.move(20, 300);
    drawableWidgetStop.setFixedSize(40, 40);
    drawableWidgetStop.setAcceptDrops(false);
    f->getRightPanel()->addWidget(&drawableWidgetStop);

    DrawableWidget drawableWidgetVoiture(new drawer(voiture));
    drawableWidgetVoiture.move(20, 350);
    drawableWidgetVoiture.setFixedSize(40, 40);
    drawableWidgetVoiture.setAcceptDrops(false);
    f->getRightPanel()->addWidget(&drawableWidgetVoiture);

    DrawableWidget drawableWidgetMoto(new drawer(moto));
    drawableWidgetMoto.move(20, 400);
    drawableWidgetMoto.setFixedSize(40, 40);
    drawableWidgetMoto.setAcceptDrops(false);
    f->getRightPanel()->addWidget(&drawableWidgetMoto);

    DrawableWidget drawableWidgetCamion(new drawer(camion));
    drawableWidgetCamion.move(20, 450);
    drawableWidgetCamion.setFixedSize(40, 40);
    drawableWidgetCamion.setAcceptDrops(false);
    f->getRightPanel()->addWidget(&drawableWidgetCamion);

    DrawableWidget drawableWidgetPieton(new drawer(pieton));
    drawableWidgetPieton.move(20, 500);
    drawableWidgetPieton.setFixedSize(40, 40);
    drawableWidgetPieton.setAcceptDrops(false);
    f->getRightPanel()->addWidget(&drawableWidgetPieton);


    f->getRightPanel()->setVisible(false);

    f->show();

    return app.exec();
}

void manager::newProjet() {

    this->carefour = new Carrefour();

    QString stringWidth = widthText->toPlainText();
    int width = stringWidth.toInt();

    QString stringHeight = heightText->toPlainText();
    int height = stringHeight.toInt();

    for (int i = 0 ; i < height ; i++) {
        for (int j = 0; j < width ; j++) {
            this->carefour->getGrille()->addWidget(new parcelle(i, j, 800/width, 400/height, this->carefour), i, j);
        }
    }

    f->getCenterPanel()->removeAll();
    f->getCenterPanel()->setLayout(this->carefour->getGrille()->getGridLayout());

    f->getTopPanel()->setVisible(true);
    f->getRightPanel()->setVisible(true);

    playButton->setDisabled(false);
    pauseButton->setDisabled((true));
    stopButton->setDisabled((true));
    saveButton->setDisabled(false);

}

void manager::createGrille() {
    delete this->carefour->getGrille();

    /*this->carefour->getGrille() = new grille();*/

    this->carefour->setGrille(new grille());

    QString stringWidth = widthText->toPlainText();
    int width = stringWidth.toInt();

    QString stringHeight = heightText->toPlainText();
    int height = stringHeight.toInt();

    for (int i = 0 ; i < height ; i++) {
        for (int j = 0; j < width ; j++) {
            this->carefour->getGrille()->addWidget(new parcelle(i, j, 800/width, 400/height, this->carefour), i, j);
        }
    }

    f->getCenterPanel()->removeAll();
    f->getCenterPanel()->setLayout(this->carefour->getGrille()->getGridLayout());

}

void manager::importProject() {

}

void manager::play() {
    valideButton->setDisabled(true);
    playButton->setDisabled(true);
    pauseButton->setDisabled(false);
    stopButton->setDisabled(false);
    saveButton->setDisabled(true);
    this->carefour->play();
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

void manager::saveToXml() {

    QDomDocument dom_doc;
    QFile fichier;
    QTextStream out;

    QString file = QFileDialog::getSaveFileName(f, tr("Sauvegarder un projet"),"",tr("(*.xml)"));
    fichier.setFileName(file);

    QDomElement projet;
    projet = dom_doc.createElement("projet");
    dom_doc.appendChild(projet);

    if (fichier.open(QIODevice::ReadWrite)){
        out.setDevice(&fichier);
        QDomElement g = dom_doc.createElement("grille");
        projet.appendChild(g);
        g.setAttribute("width",carefour->getGrille()->getWidth());
        g.setAttribute("height",carefour->getGrille()->getHeight());
        grille * gr = carefour->getGrille();

        for (int i = 0 ; i < gr->getHeight() ; i++) {
            for (int j = 0; j < gr->getWidth() ; j++) {
                QDomElement cases = dom_doc.createElement("case");
                g.appendChild(cases);
                cases.setAttribute("type",1); // Type de case
                cases.setAttribute("x",i);
                cases.setAttribute("y",j);
            }
        }

        QDomNode noeud = dom_doc.createProcessingInstruction("xml","version=\"1.0\"");
        dom_doc.insertBefore(noeud,dom_doc.firstChild());

        dom_doc.save(out,2);

        fichier.close();
    }
}


void manager::loadFromXml() {
    QString files = QFileDialog::getOpenFileName(f, tr("Ouvrir un projet"),"",tr("(*.xml)"));
    QDomDocument doc("file");
    if(files.isEmpty()) {
        cout << "Erreur à l'ouverture du document XML, Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé"<< endl;
        return;
    }

    QFileInfo fileInfo(files);
    QString path = fileInfo.filePath(); // Path vers le fichier

    QFile xml_doc(path);

    if(!xml_doc.open(QIODevice::ReadOnly))  // Si l'on n'arrive pas à ouvrir le fichier XML.
    {
         cout << "Erreur à l'ouverture du document XML, Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé"<< endl;
         return;
    }


    // Génération de la grille
    QDomElement docElem = doc.documentElement();
    QDomNodeList nodeList = docElem.elementsByTagName("projet").at(0).toElement().elementsByTagName("grille").at(0).toElement().elementsByTagName("case");
    QDomNodeList g = docElem.elementsByTagName("projet").at(0).toElement().elementsByTagName("grille");
    int type;
    int x;
    int y;

    if (nodeList.count() > 0){
       for(int i=0; i<nodeList.count(); i++){
             bool bOk = false;
             type = nodeList.at(i).attributes().namedItem("type").nodeValue().toInt(&bOk,10); // Type de case
             x = nodeList.at(i).attributes().namedItem("x").nodeValue().toInt(&bOk,10);
             y = nodeList.at(i).attributes().namedItem("y").nodeValue().toInt(&bOk,10);

             carefour->getGrille()->addWidget(new parcelle(x, y, 800/g.at(0).attributes().namedItem("width").nodeValue().toInt(&bOk,10), 400/g.at(0).attributes().namedItem("height").nodeValue().toInt(&bOk,10), this->carefour), x, y);
        }
    }

    f->getCenterPanel()->removeAll();
    f->getCenterPanel()->setLayout(this->carefour->getGrille()->getGridLayout());

}
