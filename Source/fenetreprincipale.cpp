#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"

using namespace std;
FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetrePrincipale)
{
    ui->setupUi(this);
    ui->centralwidget->setFixedSize(1480,720);
    setWindowIcon(QIcon("Logo36Officiers.png"));
    Fond *fond = new Fond();
    QHBoxLayout *layH =new QHBoxLayout;
    layH->addWidget(fond);
    ui->centralwidget->setLayout(layH);
    setWindowTitle("Le Dilem des 36 Officiers");

    /*********************** Widget d'Ouverture *******************/

    tailleGSpn  = new QSpinBox;
    tailleGSpn->setMinimum(3);
    tailleGSpn->setMaximum(6);

    tailleGLbl = new QLabel("Taille de la grille :");

    tailleGBtn = new QPushButton("Lancer");
    tailleGBtn->setIcon(QIcon("power115.png"));

    QHBoxLayout *layReg = new QHBoxLayout;
    layReg->addWidget(tailleGLbl);
    layReg->addWidget(tailleGSpn);
    layReg->addWidget(tailleGBtn);

     layOuvert = new QGridLayout;
    layOuvert->addLayout(layReg,0,0,1,10,Qt::AlignCenter);

    /************************** WidgetFantom **********************/
    widgF  = new QWidget;
    widgF->setFixedSize(980,700);

    /************************** Boutons **********************/
        deplacerBtn = new QPushButton("Déplacer");
        deplacerBtn->setIcon(QIcon("deplacer.png"));

    /************************ Formes ******************************/
    paletteDesFormes = new QGroupBox("Formes ");
    paletteDesFormes->setFixedSize(450,690);
    QPalette pal;
    pal.setColor(QPalette::WindowText,Qt::white);
    paletteDesFormes->setPalette(pal);

    /************************* Layouts *****************************/
    layoutG = new QGridLayout;
    layoutG->addWidget(widgF,0,0);
    layoutG->addWidget(paletteDesFormes,0,1);
    fond->setLayout(layoutG);

    layoutCP    = new QGridLayout;
    paletteDesFormes->setLayout(layoutCP);
    /************************* Connexion ****************************/
    connect(tailleGBtn,SIGNAL(clicked()),this,SLOT(lancer()));
    connect(ui->actionQuitter,SIGNAL(triggered()),qApp,SLOT(quit()));
    connect(ui->actionNouvellePartie,SIGNAL(triggered()),this,SLOT(nouvellePartie()));
    connect(deplacerBtn,SIGNAL(clicked()),this,SLOT(deplacer()));
    connect(ui->actionAnnuler,SIGNAL(triggered()),this,SLOT(annuler()));
    connect(ui->actionLisez_moi,SIGNAL(triggered()),this,SLOT(lisezMoi()));
    ui->actionAnnuler->setEnabled(false);
    ui->actionAnnuler->setIcon(QIcon("game50.png"));
    ui->actionQuitter->setIcon(QIcon("door13.png"));
    ui->actionNouvellePartie->setIcon(QIcon("gamepad.png"));

    ui->actionAnnuler->setShortcut(QKeySequence("Ctrl+Z"));
    ui->actionNouvellePartie->setShortcut(QKeySequence("Ctrl+N"));
    ui->actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
/********************** Centrer ************************/
   setGeometry((int)(QApplication::desktop()->width() - 1480) / 2, (int)(QApplication::desktop()->height() - 720 - 50) / 2, 1480, 720);
}

FenetrePrincipale::~FenetrePrincipale()
{
    delete ui;
}

void FenetrePrincipale::lancer()
{
    if(!formes.empty())
    {
        for(int i=0;i<formes.size();i++)
        {
              for(int j=0;j<formes.size();j++)
              {
                  formes[i][j]->setHidden(true);
                  fantomes[i][j]->setHidden(true);
                  delete formes[i][j];
                  delete fantomes[i][j];

              }
        }
        std::vector< std::vector <Forme*> >     fo;
        std::vector< std::vector <Fantome*> >     fa;
        formes=fo; fantomes=fa;
        //widgetDessin->setHidden(true);
       // layoutCP = new QGridLayout;
        //layoutGrille = new QGridLayout;
    }

    widgetDessin    = new contrePlaquet(tailleGSpn->value());
    widgetDessin->setFixedSize(980,690);
    widgetDessin->setHidden(false);
    layoutG->addWidget(widgetDessin,0,0);
    widgF->setVisible(false);
    tailleGWidget->setVisible(false);


    /********************* Formes ***********************/

    QWidget *widN1= new QWidget;
    QWidget *widN2 = new QWidget;

    switch(tailleGSpn->value())
    {
    case 3: widN1->setFixedSize(850,65); widN2->setFixedSize(90,700/tailleGSpn->value());
        break;
    case 4:widN1->setFixedSize(850,40); widN2->setFixedSize(60,700/tailleGSpn->value());
        break;
    case 5: widN1->setFixedSize(850,25); widN2->setFixedSize(38,700/tailleGSpn->value());
        break;
    case 6: widN1->setFixedSize(850,15); widN2->setFixedSize(10,700/tailleGSpn->value());
        break;
    default:
        break;
    }



    layoutGrille = new QGridLayout;
    layoutGrille->addWidget(widN1,0,0,1,tailleGSpn->value()+1);


    std::vector <Forme*> vectFo,initFo;
    std::vector <Fantome*> vectFa,initFa;
    for(int i=1;i<=tailleGSpn->value();i++)
    {   layoutGrille->addWidget(widN2,i,0,1,1);
         for(int j=1;j<=tailleGSpn->value();j++)
         {
             Forme *fo=new Forme(j,i,tailleGSpn->value());
             layoutCP->addWidget(fo,j-1,i-1);
                vectFo.push_back(fo);

             Fantome *fa = new Fantome(tailleGSpn->value(),i,j);
             layoutGrille->addWidget(fa,i,j,1,1);
             vectFa.push_back(fa);
         }
         formes.push_back(vectFo);
         fantomes.push_back(vectFa);
         vectFo=initFo;
         vectFa=initFa;

    }
layoutCP->addWidget(deplacerBtn,tailleGSpn->value(),0,1,tailleGSpn->value(),Qt::AlignCenter);

widgetDessin->setLayout(layoutGrille);

}

void FenetrePrincipale::deplacer()
{
    bool b(false);
    bool H;
    ui->actionAnnuler->setEnabled(true);
    for(int i=0;i<formes.size() && !b;i++)
    {
        for(int j=0;j<formes.size() && !b;j++)
        {
                if(formes[i][j]->estCliquee())
                {
                    for(int k=0;k<fantomes.size() && !b;k++)
                    {
                        for(int m=0;m<fantomes.size() && !b;m++)
                        {
                                if(fantomes[k][m]->estCliquee())
                                {
                                     H=false;
                                    for(int y=0;y<formes.size() && !H;y++)
                                    {
                                        for(int z=0;z<formes.size() && !H;z++)
                                        {
                                            if(formes[y][z]->estAffecte())
                                            {
             if(formes[i][j]->getCol()==formes[y][z]->getCol() || formes[i][j]->getNom()==formes[y][z]->getNom())
             {
                 if(k==formes[y][z]->getK()  || m==formes[y][z]->getM() )
                 {
                     H=true;
                 }
             }
                                     }
                                        }
                                    }

                                    if(!H)
                                    {
                                        cerr<<"!H\n";
                                    layoutGrille->addWidget(formes[i][j],fantomes[k][m]->getX(),fantomes[k][m]->getY());
                                    fantomes[k][m]->setHidden(true);
                                    fantomes[k][m]->setCliquee(false);
                                    formes[i][j]->setCliquee(false);
                                    formes[i][j]->setAffecte(true);
                                    formes[i][j]->setK(k);
                                    formes[i][j]->setM(m);
                                    b=true;
                                    pair<std::pair<int,int>,std::pair<int,int> > pp;
                                    pair <int,int> p;
                                    p.first =i; p.second=j;
                                    pp.first=p;
                                    p.first=k; p.second=m;
                                    pp.second=p;
                                    tabAnnul.push_back(pp);
                                    }else
                                    {
                                        cerr<<"H";
                                        QWidget *widgInterdit = new QWidget;
                                        widgInterdit->setWindowTitle("Déplacement intérdit");
                                        widgInterdit->setFixedSize(400,100);
                                        widgInterdit->setWindowIcon(QIcon("x button.png"));
                                        QLabel *lab=new QLabel("<strong>Vous ne pouvez pas faire ce déplacement</strong>");
                                        QGridLayout *layInt = new QGridLayout;
                                        layInt->addWidget(lab,0,0,1,4,Qt::AlignCenter);
                                        widgInterdit->setLayout(layInt);
                                        widgInterdit->show();
                                        fantomes[k][m]->setCliquee(false);
                                        formes[i][j]->setCliquee(false);

                                    }
                                }
                        }
                    }
                }
        }
    }

    bool gagne(true);
    for(int i=0; i<formes.size() && gagne;i++)
    {
        for(int j=0;j<formes.size() && gagne;j++)
        {
            if(formes[i][j]->estAffecte()==false){gagne=false;}
        }
    }

    if(gagne)
    {
        QWidget *widgGagne=new QWidget;
        widgGagne->setFixedSize(300,100);
        widgGagne->setWindowIcon(QIcon("game39.png"));
        widgGagne->setWindowTitle("Bravo !");
        QLabel  *gagneLbl= new QLabel("<strong>Bravo !</strong> Vous avez gagné ");
        QGridLayout *layGagne=new QGridLayout;
        layGagne->addWidget(gagneLbl,0,0,1,4,Qt::AlignCenter);
        widgGagne->setLayout(layGagne);
        widgGagne->show();
    }
}

void FenetrePrincipale::nouvellePartie()
{


    tailleGWidget = new QWidget;
    tailleGWidget->setFixedSize(500,200);
    tailleGWidget->setLayout(layOuvert);
    tailleGWidget->show();
}

void FenetrePrincipale::annuler()
{


    if(!tabAnnul.empty())
    {
     pair<std::pair<int,int>,std::pair<int,int> > pp(tabAnnul[tabAnnul.size()-1]);
     pair <int,int> p1(pp.first);
     pair <int,int> p2(pp.second);
     fantomes[p2.first][p2.second]->setHidden(false);
     formes[p1.first][p1.second]->setAffecte(false);
     layoutCP->addWidget(formes[p1.first][p1.second],p1.second,p1.first);
     tabAnnul.pop_back();
    }else
    {
        QMessageBox::critical(this,"Annuler","Vous ne pouvez plus faire machine arrière");
    }
}

void FenetrePrincipale::lisezMoi()
{
    Cadeau *cad=new Cadeau;
    QString inf("<br>Cette petite application a été créer par l'étudianten master R.O, <strong>Mehdi BOUZiDi</strong>,  <br>");
    inf+="<br>Option : <strong>METHODES ET MODELES POUR L'INGENIERIE ET LA RECHERCHE </strong>.<br> ";
    inf+="<br>Elle est offerte à Mr <strong>PIERRE AUDIN</strong>, afin de le remercier du bref moment dont j'ai eu l'honneur </br><br>de partager avec lui.</br> ";
    inf+="<br> </br><br>Date : <strong> 12/10/2015</strong> <br>";

    QWidget *infos = new QWidget;
    infos->setWindowIcon(QIcon("information19.png"));
infos->setWindowTitle("Lisez moi");
//infos->setWindowIcon(QIcon("info2.png"));
infos->setFixedSize(600,480);
 QLabel *auteur = new QLabel(inf);
 QGridLayout *layoutInfo =new QGridLayout;
 layoutInfo->addWidget(cad,0,0,1,4,Qt::AlignCenter);
 layoutInfo->addWidget(auteur,1,0);
 infos->setLayout(layoutInfo);
 infos->setHidden(false);
}
