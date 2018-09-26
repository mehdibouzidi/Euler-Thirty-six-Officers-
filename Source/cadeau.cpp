#include "cadeau.h"

Cadeau::Cadeau()
{
    setHidden(false);
    setFixedSize(300,300);
}

void Cadeau::paintEvent(QPaintEvent *e)
{
    QPainter *painter= new QPainter(this);

    painter->drawPixmap(0,0,300,300,QPixmap("cad.png"));
}

