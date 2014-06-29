#ifndef MANAGER_H
#define MANAGER_H

#include "fenetre.h"
#include "grille.h"
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QMenuBar>


class manager : public QObject {

    Q_OBJECT

public:
    manager();
    int begin(int argc, char *argv[]);

public slots :
    void newProjet();
    void createGrille();
    void importProject();
    void play();
    void pause();
    void stop();
    void save();

private :
    fenetre * f;
    grille *g;
    QLabel * widthLabel;
    QTextEdit * widthText;
    QLabel * heightLabel;
    QTextEdit * heightText;
    QPushButton * valideButton;
    QPushButton * playButton;
    QPushButton * pauseButton;
    QPushButton * stopButton;
    QPushButton * saveButton;
};

#endif // MANAGER_H
