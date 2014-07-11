#ifndef PARCELLE_H
#define PARCELLE_H

#include "drawablewidget.h"
#include "carrefour.h"
#include "route.h"

#include <QWidget>

class parcelle : public QWidget {

    public:
        parcelle();
        parcelle(int, int, int, int, Carrefour *);
        void removeVoiture();
        void addVoiture();
        void play();

    protected:
        void dragEnterEvent(QDragEnterEvent *);
        void dropEvent(QDropEvent *);

    private :
        int positionX;
        int positionY;
        int width;
        int height;
        DrawableWidget * drawableWidgetRoute;
        DrawableWidget * drawableWidgetVoiture;
        Carrefour * carefour;

};

#endif // PARCELLE_H
