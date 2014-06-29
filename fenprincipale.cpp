#include "Fenprincipale.h"

FenPrincipale::FenPrincipale(QWidget *parent) : QMainWindow(parent) {

    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);
}
