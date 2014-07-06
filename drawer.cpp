#include "drawer.h"

#include <QPainter>
#include <Qt>

drawer::drawer() {
    rt = route_horizontal;
}

drawer::drawer(routeType type) {
    rt = type;
}

drawer::drawer(std::string name) {
    if (name == "route_horizontal") {
        rt = route_horizontal;
    } else if (name == "route_vertical") {
       rt = route_vertical;
    } else if (name == "croisement") {
        rt = croisement;
    } else {
        rt = route_horizontal;
    }
}

std::string drawer::getStringRouteType() {
    switch (rt) {
        case route_horizontal:
            return "route_horizontal";
            break;
        case route_vertical:
            return "route_vertical";
            break;
        case croisement:
            return "croisement";
            break;
        default:
            return "";
            break;
    }
}

void drawer::drawInWidget(QWidget *widget) {
    QPainter painter(widget);
    switch (rt) {
        case route_horizontal:
            painter.setRenderHint(QPainter::Antialiasing);
            painter.setPen(Qt::white);
            painter.drawLine(0, widget->height()/4, widget->width(), widget->height()/4);
            painter.drawLine(0, (widget->height()*3)/4, widget->width(), (widget->height()*3)/4);
            painter.setPen(Qt::white);
            painter.drawRect(widget->width()/20,(widget->height()/2)-(widget->height()/20),(widget->width()/2)-(widget->width()/8),widget->height()/10);
            painter.drawRect((widget->width()/2)+(widget->width()/20),(widget->height()/2)-(widget->height()/20),(widget->width()/2)-(widget->width()/8),widget->height()/10);
            break;
        case route_vertical:
            painter.setRenderHint(QPainter::Antialiasing);
            painter.setPen(Qt::white);
            painter.drawLine((widget->width())/4, 0, (widget->width())/4, widget->height());
            painter.drawLine((widget->width()*3)/4, 0, (widget->width()*3)/4, widget->height());
            painter.setPen(Qt::white);
            painter.drawRect((widget->width()/2)-(widget->width()/20),widget->height()/20,widget->width()/10,(widget->height()/2)-(widget->height()/8));
            painter.drawRect((widget->width()/2)-(widget->width()/20),(widget->height()/2)+(widget->height()/20),widget->width()/10,(widget->height()/2)-(widget->height()/8));
            break;
        case croisement:
            painter.setRenderHint(QPainter::Antialiasing);
            painter.setPen(Qt::white);
            painter.drawLine((widget->width())/4, 0, (widget->width())/4, widget->height()/4);
            painter.drawLine((widget->width()*3)/4, 0, (widget->width()*3)/4, widget->height()/4);
            painter.drawLine((widget->width())/4, (widget->height()*3)/4, (widget->width())/4, widget->height());
            painter.drawLine((widget->width()*3)/4, (widget->height()*3)/4, (widget->width()*3)/4, widget->height());
            painter.drawLine(0, widget->height()/4, widget->width()/4, widget->height()/4);
            painter.drawLine(0, (widget->height()*3)/4, widget->width()/4, (widget->height()*3)/4);
            painter.drawLine((widget->width()*3)/4, widget->height()/4, widget->width(), widget->height()/4);
            painter.drawLine((widget->width()*3)/4, (widget->height()*3)/4, widget->width(), (widget->height()*3)/4);

            painter.drawRect(0,(widget->height()/2)-(widget->height()/20),widget->width()/8,widget->height()/10);
            painter.drawRect((widget->width()*3)/4,(widget->height()/2)-(widget->height()/20),widget->width()/8,widget->height()/10);
            painter.drawRect((widget->width()/2)-(widget->width()/20),0,widget->width()/10,widget->height()/8);
            painter.drawRect((widget->width()/2)-(widget->width()/20),(widget->height()*3)/4,widget->width()/10,widget->height()/8);
            break;
        default:
            break;
    }
}
