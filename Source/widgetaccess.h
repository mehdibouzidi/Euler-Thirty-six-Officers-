#ifndef WIDGETACCESS_H
#define WIDGETACCESS_H

#include <QObject>
#include <QWidget>

class WidgetAccess : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetAccess(QWidget *parent = 0);

signals:

public slots:
};

#endif // WIDGETACCESS_H
