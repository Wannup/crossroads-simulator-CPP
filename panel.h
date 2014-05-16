#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QList>
#include <QMouseEvent>

class Panel : public QWidget
{
    Q_OBJECT
public:
    explicit Panel(QWidget *parent = 0);
    void addWidget(QWidget * widget);
    void removeAll();
    void mousePressEvent(QMouseEvent *);

private:
    QList<QWidget *> list;

signals:

public slots:

};

#endif // PANEL_H
