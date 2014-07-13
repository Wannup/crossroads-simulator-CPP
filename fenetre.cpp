#include "fenetre.h"

fenetre::fenetre() : QWidget() {
    setFixedSize(1000, 600);
    topPanel = new Panel(this);
    topPanel->setFixedSize(900, 100);
    topPanel->move(0, 0);
    topPanel->show();
    centerPanel = new Panel(this);
    centerPanel->setFixedSize(900, 500);
    centerPanel->move(0, 100);
    centerPanel->show();
    rightPanel = new Panel(this);
    rightPanel->setFixedSize(100, 600);
    rightPanel->move(900, 0);
    rightPanel->show();
}

fenetre::fenetre(const fenetre & fen) {

}

fenetre & fenetre::operator= (const fenetre & fen) {

}

fenetre::~fenetre() {

}

 Panel * fenetre::getTopPanel() {
    return topPanel;
}

 Panel * fenetre::getCenterPanel() {
    return centerPanel;
}

 Panel * fenetre::getRightPanel() {
    return rightPanel;
}
