#ifndef CONTREPLAQUET_H
#define CONTREPLAQUET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class contrePlaquet : public QWidget
{
    Q_OBJECT
public:
    explicit contrePlaquet(QWidget *parent = 0);
             contrePlaquet(int tailleGrille);
    void paintEvent(QPaintEvent *e);
signals:

public slots:

private:
    int gTaille;
};

#endif // CONTREPLAQUET_H
