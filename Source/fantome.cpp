#include "fantome.h"

Fantome::Fantome(QWidget *parent) : QWidget(parent)
{

}

Fantome::Fantome(int tGrille, int x, int y)
{
 this->x=x; this->y=y;
    setFixedSize(900/tGrille,640/tGrille);
    connect(this,SIGNAL(clique()),this,SLOT(cliqueSL()));
    setCursor(Qt::PointingHandCursor);
    cliquee=false;
}

void Fantome::mousePressEvent(QMouseEvent *ev)
{
    emit clique();
}

void Fantome::paintEvent(QPaintEvent *e)
{/*
    QPainter *painter = new QPainter(this);

    painter->drawPixmap(0,0,QPixmap("T3/V3.png"));*/
}

bool Fantome::estCliquee() const
{
    return cliquee;
}

void Fantome::setCliquee(bool cl)
{
    cliquee=cl;
}

int Fantome::getX() const
{
    return x;
}

int Fantome::getY() const
{
    return y;
}

void Fantome::cliqueSL()
{
    if(!cliquee){cliquee=true;}else{cliquee=false;}

}

