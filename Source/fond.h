#ifndef FOND_H
#define FOND_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class Fond : public QWidget
{
    Q_OBJECT
public:
    explicit Fond(QWidget *parent = 0);

    void paintEvent(QPaintEvent *e);
signals:

public slots:
};

#endif // FOND_H
