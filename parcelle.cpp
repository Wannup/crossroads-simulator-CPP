#include "parcelle.h"
#include "voiture.h"

#include <QtGui>
#include <QApplication>
#include <QMenu>
#include <vector>

parcelle::parcelle() : QWidget() {
    this->drawableWidgetRoute = new DrawableWidget();
    this->drawableWidgetRoute->setParent(this);
    this->drawableWidgetRoute->setEnabled(false);
    this->drawableWidgetVoiture = new DrawableWidget();
    this->drawableWidgetVoiture->setParent(this);
    this->drawableWidgetVoiture->setEnabled(false);
    this->positionX = 0;
    this->positionY = 0;
    setAcceptDrops(true);
}

parcelle::parcelle(const parcelle & parc) {
    this->positionX = parc.positionX;
    this->positionY = parc.positionY;
}

parcelle & parcelle::operator= (const parcelle & parc) {
    this->positionX = parc.positionX;
    this->positionY = parc.positionY;
    return *this;
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
    this->drawableWidgetRoute->setEnabled(false);
    this->drawableWidgetVoiture = new DrawableWidget();
    this->drawableWidgetVoiture->setFixedSize(width, height);
    this->drawableWidgetVoiture->setParent(this);
    this->drawableWidgetVoiture->setEnabled(false);
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
    } else if (qs.toStdString() == "route_horizontal") {
        this->drawableWidgetRoute->setDrawer(new drawer(qs.toStdString()));
        this->drawableWidgetRoute->repaint();
        this->carefour->addRoute(new Route(new Position(this->positionX, this->positionY, horizontal)));
    } else if (qs.toStdString() == "route_vertical") {
        this->drawableWidgetRoute->setDrawer(new drawer(qs.toStdString()));
        this->drawableWidgetRoute->repaint();
        this->carefour->addRoute(new Route(new Position(this->positionX, this->positionY, vertical)));
    } else if (qs.toStdString() == "croisement") {
        this->drawableWidgetRoute->setDrawer(new drawer(qs.toStdString()));
        this->drawableWidgetRoute->repaint();
        this->carefour->addRoute(new Route(new Position(this->positionX, this->positionY, all)));
    } else {
        this->drawableWidgetRoute->setDrawer(new drawer(qs.toStdString()));
        this->drawableWidgetRoute->repaint();
    }
    this->repaint();
}

void parcelle::mousePressEvent(QMouseEvent * event) {
    if(event->button() == Qt::RightButton) {
        QPoint globalPos = this->mapToGlobal(event->pos());

        QMenu * myMenu = new QMenu(this);
        myMenu->addAction("Configurer");
        myMenu->addAction("Supprimer");
        QAction* selectedItem = myMenu->exec(globalPos);
        if (selectedItem) {
            if (selectedItem->text() == "Configurer") {
                this->carefour->getConfiguration(new Position(this->positionX, this->positionY));
            } else if (selectedItem->text() == "Supprimer") {

            }
        }
    }
}

void parcelle::play() {
    /*QWidget * widget = this->g->getWidget(this->positionX, this->positionY+1);
    if (widget != NULL) {
        parcelle * parc = (parcelle *) widget;
        parc->drawableWidgetVoiture->setDrawer(new drawer("voiture"));
        parc->drawableWidgetVoiture->repaint();
    }*/
}
