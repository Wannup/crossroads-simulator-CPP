#ifndef MANAGER_H
#define MANAGER_H

#include "fenetre.h"
#include "grille.h"

class manager : public QObject {

    Q_OBJECT

public:
    manager();
    int begin(int argc, char *argv[]);

public slots :
    void newProjet();
    void importProject();

private :
    fenetre * f;
    grille *g;
};

#endif // MANAGER_H
