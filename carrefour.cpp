#include "carrefour.h"
#include "parcelle.h"
#include "voiture.h"
#include <list>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <iostream>
#include <windows.h>

Carrefour::Carrefour() {
    g = new grille();
    this->config = new Configuration();
}

Carrefour::Carrefour(const Carrefour & carf) {
    this->g = carf.g;
    this->objetRoutes = carf.objetRoutes;
    this->routes = carf.routes;
}

Carrefour::Carrefour(std::list<Route *> r) {
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

bool Carrefour::hasRoute(Position * p) {
    std::list<Route *>::iterator it;
    for (it = this->routes.begin() ; it != this->routes.end() ; it++) {
        Route * route = (Route *) *it;
        if (*(route->getPosition()) == *p) {
            return true;
        }
    }
    return false;
}


Route Carrefour::findRouteByPosition(Position p) {
    std::list<Route *>::iterator it;
    for (it = this->routes.begin() ; it != this->routes.end() ; it++) {
        Route * route = (Route *) *it;
        if (*(route->getPosition()) == p) {
            return *route;
        }
    }
}

std::list<Vehicule> Carrefour::findVehiculeByPosition(Position * p) {
    std::list<Vehicule> vehicules;
    std::list<Vehicule *>::iterator it;
    for (it = this->objetRoutes.begin() ; it != this->objetRoutes.end() ; it++) {
        Vehicule * objr = (Vehicule *) *it;
        if (objr->getPosition() == p) {
            vehicules.push_back(*objr);
        }
    }
    return vehicules;
}

void Carrefour::setGrille(grille * gril) {
    this->g = gril;
}

grille * Carrefour::getGrille () {
    return this->g;
}

void Carrefour::addRoute(Route * route) {
    this->routes.push_back(route);
}

void Carrefour::addObjetRoute(Vehicule * objRoute) {
    this->objetRoutes.push_back(objRoute);
}

void Carrefour::getConfiguration(Position * p) {
    QWidget * configWidget = new QWidget();
    this->config->setQWidget(configWidget);
    int taille = 50;
    std::list<Route *>::iterator itRoutes;
    for (itRoutes = this->routes.begin() ; itRoutes != this->routes.end() ; itRoutes++) {
        Route * route = (Route *) *itRoutes;
        if (*(route->getPosition()) == *p) {
            this->config->setRoute(route);
            QLabel * label = new QLabel("Route", configWidget);
            label->move(200, taille);
            taille += 50;
        }
    }
    std::list<Vehicule *>::iterator itVehicule;
    for (itVehicule = this->objetRoutes.begin() ; itVehicule != this->objetRoutes.end() ; itVehicule++) {
        Vehicule * vehicule = (Vehicule *) *itVehicule;
        if (*(vehicule->getPosition()) == *p) {
            this->config->setVehicule(vehicule);
            QLabel * label = new QLabel(QString::fromStdString(vehicule->getType()), configWidget);
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
    std::list<Vehicule *>::iterator it;
    for (it = this->objetRoutes.begin() ; it != this->objetRoutes.end() ; it++) {
        Vehicule * objr = (Vehicule *) *it;
        /*Voiture * v = (Voiture *) objr;
        Position * p = v->getPosition();
        Position * pArrivee = v->getPositionArrivee();
        while (!v->estArrivee()) {
            parcelle * parc = (parcelle *) this->g->getWidget(p->getPositionX(), p->getPositionY());
            parc->removeVoiture();
             if (p->getPositionY() < pArrivee->getPositionY()) {
                v->avancer();
            } else if (p->getPositionY() < pArrivee->getPositionY()) {
                v->reculer();
            } else if (p->getPositionX() > pArrivee->getPositionX()) {
                v->tournerGauche();
            } else if (p->getPositionX() < pArrivee->getPositionX()) {
                v->tournerDroite();
            }
            parcelle * parc2 = (parcelle *) this->g->getWidget(p->getPositionX(), p->getPositionY());
            parc2->addVoiture();
        }*/
        CarrefourThread * thread = new CarrefourThread(this,objr);
        QObject::connect(thread, &CarrefourThread::positionChanged, this, &Carrefour::handlePositionChanged);
        thread->start();
    }
}

void Carrefour::valideConfig() {
    int positionX = this->config->getXTextEdit()->toPlainText().toInt();
    int positionY = this->config->getYTextEdit()->toPlainText().toInt();
    this->config->getVehicule()->setPositionArrivee(new Position(positionX, positionY));
    this->config->getQWidget()->close();
}

void Carrefour::annuleConfig() {
    this->config->getQWidget()->close();
}

void Carrefour::handlePositionChanged(Position *oldPos, Position *newPos) {
    parcelle * parc = (parcelle *) this->g->getWidget(oldPos->getPositionX(), oldPos->getPositionY());
    parc->removeVoiture();
    parcelle * parc2 = (parcelle *) this->g->getWidget(newPos->getPositionX(), newPos->getPositionY());
    parc2->addVoiture();
}

Carrefour::~Carrefour() {
    delete this->g;
}

CarrefourThread::CarrefourThread(Carrefour * carefour, Vehicule * vehicule) {
    this->c = carefour;
    this->v = vehicule;
}

void CarrefourThread::run() {
    Position * p = this->v->getPosition();
    Position * pArrivee = this->v->getPositionArrivee();
    while (!this->v->estArrivee()) {
        Position * oldPos = new Position(*p);
        bool positionHasChanged = false;
         if (p->getPositionY() < pArrivee->getPositionY()) {
             Position * pos = new Position(p->getPositionX(), p->getPositionY());
             pos->avancer();
             if (this->c->hasRoute(pos)) {
                 Route route = this->c->findRouteByPosition(*pos);
                 if (route.getPosition()->getOrientation() == horizontal || route.getPosition()->getOrientation() == all) {
                     v->avancer();
                     positionHasChanged = true;
                 }
             }
        }
        if (p->getPositionY() > pArrivee->getPositionY() && !positionHasChanged) {
            Position * pos = new Position(p->getPositionX(), p->getPositionY());
            pos->reculer();
            if (this->c->hasRoute(pos)) {
                Route route = this->c->findRouteByPosition(*pos);
                if (route.getPosition()->getOrientation() == horizontal || route.getPosition()->getOrientation() == all) {
                    v->reculer();
                    positionHasChanged = true;
                }
            }
        } else if (p->getPositionX() > pArrivee->getPositionX() && !positionHasChanged) {
            Position * pos = new Position(p->getPositionX(), p->getPositionY());
            pos->gauche();
            if (this->c->hasRoute(pos)) {
                Route route = this->c->findRouteByPosition(*pos);
                if (route.getPosition()->getOrientation() == vertical || route.getPosition()->getOrientation() == all) {
                    v->tournerGauche();
                    positionHasChanged = true;
                }
            }
        } else if (p->getPositionX() < pArrivee->getPositionX() && !positionHasChanged) {
            Position * pos = new Position(p->getPositionX(), p->getPositionY());
            pos->droite();
            if (this->c->hasRoute(pos)) {
                Route route = this->c->findRouteByPosition(*pos);
                if (route.getPosition()->getOrientation() == vertical || route.getPosition()->getOrientation() == all) {
                    v->tournerDroite();
                    positionHasChanged = true;
                }
            }
        }
        if (positionHasChanged) {
            emit positionChanged(oldPos, p);
        }
        Sleep(uint(200));
    }
}

