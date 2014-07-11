#ifndef GRILLE_H
#define GRILLE_H
#include <QGridLayout>
#include <QWidget>
#include <QVector>
#include "tableaudeuxdimension.h"
#include <vector>

class grille {

    public:
        grille();
        grille(QWidget *parent);
        QGridLayout* getGridLayout();
        void addWidget(QWidget * widget, int i, int j);
        QWidget * getWidget(int, int);
        std::vector<QWidget *> getAdjacentWidget (int, int);
        ~grille();

    private :
        QGridLayout *gridLayout;
        tableauDeuxDimension<QWidget *> * widgets;

};

#endif // GRILLE_H
