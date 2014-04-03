#ifndef GRILLE_H
#define GRILLE_H
#include <QGridLayout>
#include <QWidget>

class grille {

public:
    grille();
    grille(QWidget *parent);
    QGridLayout* getGridLayout();

private :
    QGridLayout *gridLayout;

};

#endif // GRILLE_H
