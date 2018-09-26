#include "forme.h"

Forme::Forme(QWidget *parent) : QWidget(parent)
{

}

Forme::Forme(int nom,int i, int t)
{
    taille=t;
    this->nom=nom;
    couleur="T6/";

    switch (i)
    {
    case 1 : couleur+="R";
        break;
    case 2 : couleur+="V";
        break;
    case 3 : couleur+="B";
        break;
    case 4 : couleur+="M";
        break;
    case 5 : couleur+="J";
        break;
    case 6 : couleur+="O";
        break;
    default :
        break;
    }
    couleur+=QString::number(nom)+".png";
    col=i;
    cliquee=false;

    connect(this,SIGNAL(formCliquee()),this,SLOT(formCliqueeSl()));
    setCursor(Qt::PointingHandCursor);
    if(taille==6)
    {
        setFixedWidth(110);
    }
    affecte=false;
    k=0;
    m=0;
}

void Forme::paintEvent(QPaintEvent *e)
{
    QPainter *painter = new QPainter(this);

    if(taille==6){
    painter->drawPixmap(0,0,110,110,QPixmap(couleur));
              }else
    {
        painter->drawPixmap(0,0,110,110,QPixmap(couleur));
    }
    }

void Forme::mousePressEvent(QMouseEvent *ev)
{
    emit formCliquee();
}

bool Forme::estCliquee() const
{
    return cliquee;
}

void Forme::setCliquee(bool cl)
{
    cliquee=cl;

    if(cl)
    {
    couleur="T6/";
            switch (col)
            {
            case 1 : couleur+="R";
                break;
            case 2 : couleur+="V";
                break;
            case 3 : couleur+="B";
                break;
            case 4 : couleur+="M";
                break;
            case 5 : couleur+="J";
                break;
            case 6 : couleur+="O";
                break;
            default :
                break;
            }
            couleur+=QString::number(nom)+"L.png";

            cliquee=true;
                }
    else
    {
        couleur="T6/";
                switch (col)
                {
                case 1 : couleur+="R";
                    break;
                case 2 : couleur+="V";
                    break;
                case 3 : couleur+="B";
                    break;
                case 4 : couleur+="M";
                    break;
                case 5 : couleur+="J";
                    break;
                case 6 : couleur+="O";
                    break;
                default :
                    break;
                }

                couleur+=QString::number(nom)+".png";
                cliquee=false;
    }
    setHidden(true);
    setHidden(false);
}

bool Forme::estAffecte() const
{
    return affecte;
}

void Forme::setAffecte(bool b)
{
    affecte=b;
}

int Forme::getK() const
{
    return k;
}

int Forme::getM() const
{
    return m;
}

void Forme::setK(int kk)
{
    k=kk;
}

void Forme::setM(int mm)
{
    m=mm;
}

int Forme::getNom() const
{
    return nom;
}

int Forme::getCol() const
{
    return col;
}

void Forme::formCliqueeSl()
{
    if(!cliquee)
    {
    couleur="T6/";
            switch (col)
            {
            case 1 : couleur+="R";
                break;
            case 2 : couleur+="V";
                break;
            case 3 : couleur+="B";
                break;
            case 4 : couleur+="M";
                break;
            case 5 : couleur+="J";
                break;
            case 6 : couleur+="O";
                break;
            default :
                break;
            }
            couleur+=QString::number(nom)+"L.png";

            cliquee=true;
                }
    else
    {
        couleur="T6/";
                switch (col)
                {
                case 1 : couleur+="R";
                    break;
                case 2 : couleur+="V";
                    break;
                case 3 : couleur+="B";
                    break;
                case 4 : couleur+="M";
                    break;
                case 5 : couleur+="J";
                    break;
                case 6 : couleur+="O";
                    break;
                default :
                    break;
                }

                couleur+=QString::number(nom)+".png";
                cliquee=false;
    }
    setHidden(true);
    setHidden(false);

    }

