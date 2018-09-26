#ifndef FORME_H
#define FORME_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>


class Forme : public QWidget
{
    Q_OBJECT
public:
    explicit Forme(QWidget *parent = 0);
             Forme(int nom, int i, int t);

        void paintEvent(QPaintEvent *e);
        void mousePressEvent(QMouseEvent *ev);
        bool estCliquee()const;
        void setCliquee(bool cl);
        bool estAffecte()const;
        void setAffecte(bool b);
        int getK()const;
        int getM()const;
        void setK(int kk);
        void setM(int mm);

        int getNom()const;
        int getCol()const;

signals:
    void formCliquee();
public slots:
    void formCliqueeSl();
private :
        int nom;
        int col;
        QString couleur;
        int taille;
        bool cliquee;
        bool affecte;
        int    k,m;
};

#endif // FORME_H
