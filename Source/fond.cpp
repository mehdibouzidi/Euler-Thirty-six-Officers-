#include "fond.h"

Fond::Fond(QWidget *parent) : QWidget(parent)
{
    setFixedSize(1480,720);
}

void Fond::paintEvent(QPaintEvent *e)
{
    QPainter    *painter=new QPainter(this);

    painter->drawPixmap(0,0,1480,720,QPixmap("fEcran.png"));
}

