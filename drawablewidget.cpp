#include "drawablewidget.h"
#include <stddef.h>

#include <QtGui>
#include <QApplication>

DrawableWidget::DrawableWidget() {
    myDrawer = NULL;
    setPalette(Qt::transparent);
}

DrawableWidget::DrawableWidget(const DrawableWidget & drawableWidget) {

}

DrawableWidget & DrawableWidget::operator= (const DrawableWidget & drawableWidget) {

}

DrawableWidget::~DrawableWidget() {

}

DrawableWidget::DrawableWidget(drawer *d) {
    myDrawer = d;
    QPalette palette(DrawableWidget::palette());
    palette.setColor(QPalette::Background, Qt::darkGray);
    setAutoFillBackground(true);
    setPalette(palette);
}

void DrawableWidget::setDrawer(drawer *d) {
    myDrawer = d;
}

void DrawableWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        startPos = event->pos();
        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(QString::fromStdString(myDrawer->getStringRouteType()));
        drag->setMimeData(mimeData);
        Qt::DropAction dropAction = drag->exec();
    }
}

void DrawableWidget::mouseMoveEvent(QMouseEvent * event) {
    if (event->button() == Qt::LeftButton) {
        int distance = (event->pos() - startPos).manhattanLength();
        if (distance >= QApplication::startDragDistance()) {
            QMimeData *mimeData = new QMimeData;
            mimeData->setText(QString::fromStdString(myDrawer->getStringRouteType()));
            QDrag *drag = new QDrag(this);
            drag->setMimeData(mimeData);
        }
    }
}

void DrawableWidget::paintEvent(QPaintEvent *) {
    if (myDrawer != NULL) {
        myDrawer->drawInWidget(this);
    }
}
