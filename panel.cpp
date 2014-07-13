#include "panel.h"
#include <QDrag>
#include <QMimeData>

Panel::Panel() {

}

Panel::Panel(const Panel & panel) {

}

Panel & Panel::operator= (const Panel & panel) {

}

Panel::~Panel() {

}

Panel::Panel(QWidget *parent) : QWidget(parent) {

}

void Panel::addWidget(QWidget *widget) {
    widget->setParent(this);
    list.append(widget);
}

void Panel::removeAll() {
    QWidget *widget;
    while (!list.isEmpty()) {
        widget = list.takeFirst();
        delete widget;
    }
}

void Panel::mousePressEvent(QMouseEvent * event) {
    if (event->button() == Qt::LeftButton) {
         QDrag *drag = new QDrag(this);
         QMimeData *mimeData = new QMimeData;
         mimeData->setText("test");
         drag->setMimeData(mimeData);
         Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
     }
}
