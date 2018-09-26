#include <QApplication>
#include <QtGui>

#include "fenetreprincipale.h"



int main(int argc,char *argv[])
{
     QApplication app(argc,argv);

    FenetrePrincipale fenetre;
    fenetre.show();

   /* int desktop_width = fenetre.width();;
    int desktop_height = fenetre.height();
    int x = desktop_width / 2 - fenetre.width() / 2;
    int y = desktop_height / 2 - fenetre.height() / 2 - 25;
    fenetre.move(QPoint(x, y));
*/
return app.exec();
}

