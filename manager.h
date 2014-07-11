#ifndef MANAGER_H
#define MANAGER_H

#include "carrefour.h"
#include "fenetre.h"
#include "grille.h"

#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QMenuBar>
#include <QtXml>
#include <iostream>
#include <string>

using namespace std;

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
    void saveToXml(string path, string name);
    void loadFromXml(string path);

private :
    fenetre * f;
    Carrefour * carefour;
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
