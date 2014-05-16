#ifndef FENETRE_H
#define FENETRE_H

#include <QWidget>
#include "panel.h"

class fenetre : public QWidget {

    public:
        fenetre();
        Panel * getTopPanel();
        Panel * getCenterPanel();
        Panel * getRightPanel();
    private :
        Panel * topPanel;
        Panel * centerPanel;
        Panel * rightPanel;
    
};

#endif // FENETRE_H
