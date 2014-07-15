#include "carrefour.h"
#include "parcelle.h"
#include "voiture.h"
#include <list>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <iostream>

Carrefour::Carrefour() {
    g = new grille();
    this->config = new Configuration();
}

Carrefour::Carrefour(const Carrefour & carf) {
    this->g = carf.g;
    this->objetRoutes = carf.objetRoutes;
    this->routes = carf.routes;
}

Carrefour::Carrefour(std::list<Route> r) {
    routes = r;
}

Carrefour & Carrefour::operator=(const Carrefour & carf) {
    if (this == &carf) {
        return *this;
    }
    this->g = carf.g;
    this->objetRoutes = carf.objetRoutes;
    this->routes = carf.routes;
    return *this;
}

Route Carrefour::findRouteByPosition(Position p) {
    std::list<Route>::iterator it;
    for (it = this->routes.begin() ; it != this->routes.end() ; it++) {
        Route route = (Route) *it;
        if (route.getPosition() == &p) {
            return route;
        }
    }
}

std::list<Vehicule> Carrefour::findVehiculeByPosition(Position * p) {
    std::list<Vehicule> vehicules;
    std::list<Vehicule>::iterator it;
    for (it = this->objetRoutes.begin() ; it != this->objetRoutes.end() ; it++) {
        Vehicule objr = (Vehicule) *it;
        if (objr.getPosition() == p) {
            vehicules.push_back(objr);
        }
    }
    return vehicules;
}

grille * Carrefour::getGrille () {
    return this->g;
}

void Carrefour::addObjetRoute(Vehicule * objRoute) {
    this->objetRoutes.push_back(*objRoute);
}

void Carrefour::getConfiguration(Position * p) {
    QWidget * configWidget = new QWidget();
    this->config->setQWidget(configWidget);
    int taille = 50;
    std::list<Route>::iterator itRoutes;
    for (itRoutes = this->routes.begin() ; itRoutes != this->routes.end() ; itRoutes++) {
        Route route = (Route) *itRoutes;
        if (route.getPosition() == p) {
            this->config->setRoute(&route);
            QLabel * label = new QLabel("Route", configWidget);
            label->move(50, taille);
            taille += 50;
        }
    }
    std::list<Vehicule>::iterator itVehicule;
    for (itVehicule = this->objetRoutes.begin() ; itVehicule != this->objetRoutes.end() ; itVehicule++) {
        Vehicule objr = (Vehicule) *itVehicule;
        if (*(objr.getPosition()) == *p) {
            this->config->setVehicule(&objr);
            QLabel * label = new QLabel(QString::fromStdString(objr.getType()), configWidget);
            label->move(200, taille);
            taille += 50;
            QLabel * labelPositionArrivee = new QLabel("Position d'arrivee", configWidget);
            labelPositionArrivee->move(50, taille);
            QLabel * labelX = new QLabel("X : ", configWidget);
            labelX->move(150, taille);
            QTextEdit * xTextEdit = new QTextEdit(configWidget);
            xTextEdit->move(180, taille);
            xTextEdit->setFixedSize(50, 30);
            this->config->setXTextEdit(xTextEdit);
            QLabel * labelY = new QLabel("Y : ", configWidget);
            labelY->move(250, taille);
            QTextEdit * yTextEdit = new QTextEdit(configWidget);
            yTextEdit->move(280, taille);
            yTextEdit->setFixedSize(50, 30);
            this->config->setYTextEdit(yTextEdit);
            taille += 50;
            QLabel * labelNbVehicule = new QLabel("Nb vehicule : ", configWidget);
            labelNbVehicule->move(50, taille);
            QTextEdit * nbVehiculeTextEdit = new QTextEdit(configWidget);
            nbVehiculeTextEdit->move(150, taille);
            nbVehiculeTextEdit->setFixedSize(50, 30);
            taille += 50;
        }
    }
    QPushButton * valideButton = new QPushButton("valide", configWidget);
    QObject::connect(valideButton, SIGNAL(clicked()), this, SLOT(valideConfig()));
    valideButton->move(100, taille);
    QPushButton * annuleButton = new QPushButton("annule", configWidget);
    QObject::connect(annuleButton, SIGNAL(clicked()), this, SLOT(annuleConfig()));
    annuleButton->move(300, taille);
    configWidget->show();
}

void Carrefour::play() {
    std::list<Vehicule>::iterator it;
    for (it = this->objetRoutes.begin() ; it != this->objetRoutes.end() ; it++) {
        Vehicule objr = (Vehicule) *it;
        Voiture * v = (Voiture *) &objr;
        Position * p = v->getPosition();
        parcelle * parc = (parcelle *) this->g->getWidget(p->getPositionX(), p->getPositionY());
        parc->removeVoiture();
        v->avancer();
        parcelle * parc2 = (parcelle *) this->g->getWidget(p->getPositionX(), p->getPositionY());
        parc2->addVoiture();
    }
}

void Carrefour::valideConfig() {
    int positionX = this->config->getXTextEdit()->toPlainText().toInt();
    int positionY = this->config->getYTextEdit()->toPlainText().toInt();
    //this->config->getVehicule()->setPositionArrivee(new Position(positionX, positionY));
    this->config->getQWidget()->close();
}

void Carrefour::annuleConfig() {
    this->config->getQWidget()->close();
}

Carrefour::~Carrefour() {
    delete this->g;
}

