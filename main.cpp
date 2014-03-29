#include <iostream>
#include <QApplication>
#include <QtWidgets>
#include "fenPrincipale.h"

using namespace std;

int main(int argc, char *argv[])
{
        QApplication app(argc, argv);

        FenPrincipale fenetre;
        fenetre.show();

        return app.exec();
}

