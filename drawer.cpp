#include "drawer.h"

#include <QPainter>
#include <Qt>

drawer::drawer() {
    rt = route_horizontal;
}

drawer::drawer(const drawer & draw) {

}

drawer & drawer::operator= (const drawer & draw) {

}

drawer::~drawer() {

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
    } else if (name == "feu_tricolor") {
        rt = feu_tricolor;
    } else if (name == "panneau_stop") {
        rt = panneau_stop;
    } else if (name == "voiture") {
        rt = voiture;
    } else if (name == "camion") {
        rt = camion;
    } else if (name == "moto") {
        rt = moto;
    } else if (name == "pieton") {
        rt = pieton;
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
        case feu_tricolor:
            return "feu_tricolor";
            break;
        case panneau_stop:
            return "panneau_stop";
            break;
        case voiture:
            return "voiture";
            break;
        case camion:
            return "camion";
            break;
        case moto:
            return "moto";
            break;
        case pieton:
            return "pieton";
            break;
        default:
            return "";
            break;
    }
}

void drawer::drawInWidget(QWidget *widget) {
    QPainter painter(widget);
    painter.setRenderHint(QPainter::Antialiasing);
    switch (rt) {
        case route_horizontal:
            painter.setPen(Qt::white);
            painter.drawLine(0, widget->height()/4, widget->width(), widget->height()/4);
            painter.drawLine(0, (widget->height()*3)/4, widget->width(), (widget->height()*3)/4);
            painter.fillRect(widget->width()/20,(widget->height()/2)-(widget->height()/20),(widget->width()/2)-(widget->width()/8),widget->height()/10,Qt::white);
            painter.fillRect((widget->width()/2)+(widget->width()/20),(widget->height()/2)-(widget->height()/20),(widget->width()/2)-(widget->width()/8),widget->height()/10,Qt::white);
            break;
        case route_vertical:
            painter.setPen(Qt::white);
            painter.drawLine((widget->width())/4, 0, (widget->width())/4, widget->height());
            painter.drawLine((widget->width()*3)/4, 0, (widget->width()*3)/4, widget->height());
            painter.fillRect((widget->width()/2)-(widget->width()/20),widget->height()/20,widget->width()/10,(widget->height()/2)-(widget->height()/8),Qt::white);
            painter.fillRect((widget->width()/2)-(widget->width()/20),(widget->height()/2)+(widget->height()/20),widget->width()/10,(widget->height()/2)-(widget->height()/8),Qt::white);
            break;
        case croisement:
            painter.setPen(Qt::white);
            painter.drawLine((widget->width())/4, 0, (widget->width())/4, widget->height()/4);
            painter.drawLine((widget->width()*3)/4, 0, (widget->width()*3)/4, widget->height()/4);
            painter.drawLine((widget->width())/4, (widget->height()*3)/4, (widget->width())/4, widget->height());
            painter.drawLine((widget->width()*3)/4, (widget->height()*3)/4, (widget->width()*3)/4, widget->height());
            painter.drawLine(0, widget->height()/4, widget->width()/4, widget->height()/4);
            painter.drawLine(0, (widget->height()*3)/4, widget->width()/4, (widget->height()*3)/4);
            painter.drawLine((widget->width()*3)/4, widget->height()/4, widget->width(), widget->height()/4);
            painter.drawLine((widget->width()*3)/4, (widget->height()*3)/4, widget->width(), (widget->height()*3)/4);

            painter.fillRect(0,(widget->height()/2)-(widget->height()/20),widget->width()/8,widget->height()/10,Qt::white);
            painter.fillRect((widget->width()*3)/4,(widget->height()/2)-(widget->height()/20),widget->width()/8,widget->height()/10,Qt::white);
            painter.fillRect((widget->width()/2)-(widget->width()/20),0,widget->width()/10,widget->height()/8,Qt::white);
            painter.fillRect((widget->width()/2)-(widget->width()/20),(widget->height()*3)/4,widget->width()/10,widget->height()/8,Qt::white);
            break;
        case feu_tricolor:
            painter.setPen(Qt::white);
            painter.drawLine((widget->width())/4, 0, (widget->width())/4, widget->height());
            painter.drawLine((widget->width()*3)/4, 0, (widget->width()*3)/4, widget->height());

            painter.fillRect((widget->width()/2)-(widget->width()/20),widget->height()/16,widget->width()/10,widget->height()/4,Qt::red);
            painter.fillRect((widget->width()/2)-(widget->width()/20),(widget->height()*3)/8,widget->width()/10,widget->height()/4,Qt::yellow);
            painter.fillRect((widget->width()/2)-(widget->width()/20),(widget->height()*11)/16,widget->width()/10,widget->height()/4,Qt::green);
            break;
        case panneau_stop:
            painter.setPen(Qt::red);
            painter.drawEllipse(0, 0, 35, 35);
            painter.setPen(Qt::black);
            painter.drawText(5, 20, "STOP");
            break;
        case voiture:
            painter.fillRect(widget->width()/10,(widget->height()/2)+(widget->height()/20),widget->width()/4,(widget->height()/4) - (widget->height()/20),Qt::red);
            break;
        case moto:
            painter.fillRect(widget->width()/10,(widget->height()/2)+(widget->height()/20),widget->width()/4,(widget->height()/4) - (widget->height()/20),Qt::blue);
            break;
        case camion:
            painter.fillRect(widget->width()/10,(widget->height()/2)+(widget->height()/20),widget->width()/4,(widget->height()/4) - (widget->height()/20),Qt::green);
            break;
        case pieton:
            painter.fillRect(widget->width()/10,(widget->height()/2)+(widget->height()/20),widget->width()/4,(widget->height()/4) - (widget->height()/20),Qt::white);
            break;
        default:
            break;
    }
}
