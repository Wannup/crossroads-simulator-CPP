#ifndef DRAWABLEWIDGET_H
#define DRAWABLEWIDGET_H

#include "drawer.h"
#include <QWidget>

class DrawableWidget : public QWidget {

    public:
        DrawableWidget();
        DrawableWidget(drawer *d);

    protected:
        void paintEvent(QPaintEvent *);
        void mousePressEvent(QMouseEvent *);
        void mouseMoveEvent(QMouseEvent *);
        void dragEnterEvent(QDragEnterEvent *);
        void dropEvent(QDropEvent *);

    private:
        drawer * myDrawer;
        QPoint startPos;
};

#endif // DRAWABLEWIDGET_H
