#ifndef MANAGER_H
#define MANAGER_H

#include "fenetre.h"
#include "grille.h"
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

class manager : public QObject {

    Q_OBJECT

public:
    manager();
    int begin(int argc, char *argv[]);

public slots :
    void newProjet();
    void createGrille();
    void importProject();

private :
    fenetre * f;
    grille *g;
    QLabel * widthLabel;
    QTextEdit * widthText;
    QLabel * heightLabel;
    QTextEdit * heightText;
    QPushButton * valideButton;
};

#endif // MANAGER_H
