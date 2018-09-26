#ifndef FANTOME_H
#define FANTOME_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <iostream>

class Fantome : public QWidget
{
    Q_OBJECT
public:
    explicit Fantome(QWidget *parent = 0);
             Fantome(int tGrille,int x,int y);

             void mousePressEvent(QMouseEvent *ev);
             void paintEvent(QPaintEvent *e);
             bool estCliquee()const;
             void setCliquee(bool cl);
             int getX()const;
             int getY()const;
signals:
    void clique();
public slots:
    void cliqueSL();
private:
             bool cliquee;
             int x,y;
};

#endif // FANTOME_H
