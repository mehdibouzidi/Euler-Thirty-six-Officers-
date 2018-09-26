#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QMainWindow>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QApplication>
#include <QDesktopWidget>
#include <QtGui>
#include <QMessageBox>
#include <vector>
#include <map>
#include <iostream>

#include "contreplaquet.h"
#include "forme.h"
#include "fantome.h"
#include "fond.h"
#include "cadeau.h"
namespace Ui {
class FenetrePrincipale;
}

class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    explicit FenetrePrincipale(QWidget *parent = 0);
    ~FenetrePrincipale();

private slots:
    void lancer();
    void deplacer();
    void nouvellePartie();
    void annuler();
    void lisezMoi();
private:
    Ui::FenetrePrincipale *ui;
    QGridLayout         *layoutG;
    QGridLayout         *layoutCP,*layoutGrille,*layOuvert;
    contrePlaquet       *widgetDessin;
    QWidget             *widgF;
    QGroupBox           *paletteDesFormes;
    QWidget             *tailleGWidget;
    QSpinBox            *tailleGSpn;
    QLabel              *tailleGLbl;
    QPushButton         *tailleGBtn,*deplacerBtn;
    std::vector< std::vector <Forme*> >     formes;
    std::vector< std::vector <Fantome*> >     fantomes;
    std::vector<std::pair<std::pair<int,int>,std::pair<int,int> > >  tabAnnul;

};

#endif // FENETREPRINCIPALE_H
