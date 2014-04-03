#ifndef PARCELLE_H
#define PARCELLE_H

#include <QWidget>
#include <QPushButton>

class parcelle : public QWidget {

public:
    parcelle();

private :
    QPushButton *bouton;
};

#endif // PARCELLE_H
