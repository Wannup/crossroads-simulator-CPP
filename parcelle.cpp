#include "parcelle.h"
#include "voiture.h"

#include <QtGui>
#include <QApplication>
#include <vector>

parcelle::parcelle() : QWidget() {
    this->drawableWidgetRoute = new DrawableWidget();
    this->drawableWidgetRoute->setParent(this);
    this->drawableWidgetVoiture = new DrawableWidget();
    this->drawableWidgetVoiture->setParent(this);
    setAcceptDrops(true);
}

parcelle::parcelle(const parcelle & parc) {

}

parcelle & parcelle::operator= (const parcelle & parc) {

}

parcelle::~parcelle() {

}

parcelle::parcelle(int x, int y, int w, int h, Carrefour * caref) {
    positionX = x;
    positionY = y;
    width = w;
    height = h;
    carefour = caref;
    this->drawableWidgetRoute = new DrawableWidget();
    this->drawableWidgetRoute->setFixedSize(width, height);
    this->drawableWidgetRoute->setParent(this);
    this->drawableWidgetVoiture = new DrawableWidget();
    this->drawableWidgetVoiture->setFixedSize(width, height);
    this->drawableWidgetVoiture->setParent(this);
    this->drawableWidgetVoiture->setWindowOpacity(0.1);
    QPalette palette(parcelle::palette());
    palette.setColor(QPalette::Background, Qt::darkGray);
    setAutoFillBackground(true);
    setPalette(palette);
    setAcceptDrops(true);
}

void parcelle::removeVoiture() {
    this->drawableWidgetVoiture->setDrawer(new drawer());
    this->drawableWidgetVoiture->repaint();
}

void parcelle::addVoiture() {
    this->drawableWidgetVoiture->setDrawer(new drawer("voiture"));
    this->drawableWidgetVoiture->repaint();
}


void parcelle::dragEnterEvent(QDragEnterEvent *event) {
    event->acceptProposedAction();
}

void parcelle::dropEvent(QDropEvent * event) {
    event->acceptProposedAction();
    QString qs = event->mimeData()->text();
    if (qs.toStdString() == "voiture") {
        this->drawableWidgetVoiture->setDrawer(new drawer(qs.toStdString()));
        this->drawableWidgetVoiture->repaint();
        this->carefour->addObjetRoute(new Voiture(new Position(this->positionX, this->positionY)));
    } else {
        bool dropAuthorized = true;
        /*vector<QWidget *> vec = this->g->getAdjacentWidget(this->positionX, this->positionY);
        vector<QWidget *>::iterateur it ;
        for (it = vec.begin() ; it != vec.end() ; it++) {
            if (*it != NULL) {
                parcelle * parc = (parcelle) *it;
                if (parc) {
                    cout << "authorized to put route";
                } else {
                    cout << "not authorized to put route";
                }
            }
        }*/
        if (dropAuthorized) {
            this->drawableWidgetRoute->setDrawer(new drawer(qs.toStdString()));
            this->drawableWidgetRoute->repaint();
        }
    }
    this->repaint();
}

void parcelle::play() {
    /*QWidget * widget = this->g->getWidget(this->positionX, this->positionY+1);
    if (widget != NULL) {
        parcelle * parc = (parcelle *) widget;
        parc->drawableWidgetVoiture->setDrawer(new drawer("voiture"));
        parc->drawableWidgetVoiture->repaint();
    }*/
}
