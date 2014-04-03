/*#include <iostream>
#include <QApplication>
#include <QtWidgets>
#include "fenPrincipale.h"

using namespace std;*/

#include "manager.h"

int main(int argc, char *argv[])
{
    /*    QApplication app(argc, argv);

        FenPrincipale fenetre;
        fenetre.show();

        return app.exec();
	*/
	manager m;

    return m.begin(argc, argv);
}

