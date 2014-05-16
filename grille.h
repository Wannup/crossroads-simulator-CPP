#ifndef GRILLE_H
#define GRILLE_H
#include <QGridLayout>
#include <QWidget>
#include <QVector>
#include "tableaudeuxdimension.h"

class grille {

public:
    grille();
    grille(QWidget *parent);
    QGridLayout* getGridLayout();
    void addWidget(QWidget * widget, int i, int j);
    ~grille();

private :
    QGridLayout *gridLayout;
    tableauDeuxDimension<QWidget *> * widgets;

};

#endif // GRILLE_H
