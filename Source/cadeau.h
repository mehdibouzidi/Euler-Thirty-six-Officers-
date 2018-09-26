#ifndef CADEAU_H
#define CADEAU_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class Cadeau : public QWidget
{
public:
    Cadeau();

    void paintEvent(QPaintEvent *e);
};

#endif // CADEAU_H
