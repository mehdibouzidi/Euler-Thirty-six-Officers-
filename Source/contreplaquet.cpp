#include "contreplaquet.h"

contrePlaquet::contrePlaquet(QWidget *parent) : QWidget(parent)
{

}



contrePlaquet::contrePlaquet(int tailleGrille)
{
     gTaille=tailleGrille;
     setHidden(false);
}

void contrePlaquet::paintEvent(QPaintEvent *e)
{
    QPainter *painter = new QPainter(this);

    painter->drawPixmap(0,0,940,760,QPixmap("Fond.png"));


    QPen stilo(Qt::black);
         stilo.setWidth(5);
    painter->setPen(stilo);
    painter->drawRect(15,35,900,640);
painter->setOpacity(0.4);
    int cote1=900/gTaille;
    int cote2=640/gTaille;

    for(int i=1;i<gTaille;i++)
    {
        painter->drawLine(i*cote1+15,35,i*cote1+15,675);
    }

    for(int i=1;i<gTaille;i++)
    {

        painter->drawLine(15,i*cote2+35,915,i*cote2+35);
    }
/*
    int x=69-gTaille*gTaille;

    int y;
    switch(gTaille)
    {
    case 3 : y=45;
        break;
    case 4 : y=42;
        break;
    case 5 : y=41;
        break;
    case 6 : y= 42;
        break;
        default:
        break;
    }

    for(int i=0;i<gTaille;i++)
    {
        for(int j=0;j<gTaille;j++)
        {
                painter->drawEllipse(x,y,580/gTaille,580/gTaille);
                x+=cote1;
        }
        y+=cote2;
        x=69-gTaille*gTaille;
    }*/
}

