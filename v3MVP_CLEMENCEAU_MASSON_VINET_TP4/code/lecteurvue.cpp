#include "ui_lecteurvue.h"
#include "presentation.h"

lecteurVue::lecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lecteurVue)
{
    ui->setupUi(this);

    // Connexions pour les boutons
    QObject::connect(ui->bSuivant, SIGNAL(clicked()), this, SLOT(demanderAvancer()));
    QObject::connect(ui->bPrecedent, SIGNAL(clicked()), this, SLOT(demanderReculer()));
    QObject::connect(ui->bPause, SIGNAL(clicked()), this, SLOT(demanderDepartArretAuto()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(quitterApplication()));


    // Connexions pour les actions du menu
    QObject::connect(ui->actionChargerDiapo, SIGNAL(triggered()), this, SLOT(demanderChargerDiapo()));
    QObject::connect(ui->actionEnleverDiapo, SIGNAL(triggered()), this, SLOT(demanderEnleverDiapo()));
    QObject::connect(ui->actionVitesseDefilement, SIGNAL(triggered()), this, SLOT(demanderChangerVitesse()));
    QObject::connect(ui->actionAutomatique, SIGNAL(triggered()), this, SLOT(demanderChangerModeAutomatique()));
    QObject::connect(ui->actionManuel, SIGNAL(triggered()), this, SLOT(demanderChangerModeManuel()));
    QObject::connect(ui->actionAPropos, SIGNAL(triggered()), this, SLOT(demanderAProposs()));

    //navigation entre les bouton avec tab
    QWidget::setTabOrder(ui->bPrecedent, ui->bPause);
    QWidget::setTabOrder(ui->bPause, ui->bSuivant);
}

lecteurVue::~lecteurVue()
{
    delete ui;
}

void lecteurVue::majInterface(Modele::UnEtat e){
    /*switch (e){
        case Modele::automatique:
            ui->label->setText("allumé !");
            ui->label->setPixmap(QPixmap::fromImage(QImage(":/ampoule/images/ampouleAllumee2.PNG")));
            ui->bPause->setEnabled(false);
            ui->bEteindre->setEnabled(true);
            break;
        case Modele::manuel:
            ui->label->setText("éteint !");
            ui->label->setPixmap(QPixmap::fromImage(QImage(":/ampoule/images/ampouleEteinte2.PNG")));
            ui->bAllumer->setEnabled(true);
            ui->bEteindre->setEnabled(false);
            break;
       default: break;
    }*/
}

void lecteurVue::setPresentation(Presentation * p)
{
    m_MaPresentation = p;
}



void lecteurVue::demanderAvancer(){
    qDebug() << "L'image avance";
    m_MaPresentation->demanderAvancer();
}

void lecteurVue::demanderReculer(){
    qDebug() << "L'image recule";
    m_MaPresentation->demanderAvancer();
}

void lecteurVue::demanderDepartArretAuto(){
    qDebug() << "Le défilement d'image se met en pause / avance en mode auto";
    m_MaPresentation->demanderDepartArretAuto();
}

void lecteurVue::demanderChangerVitesse(){
    qDebug() << "La fenêtre pour changer la vitesse apparait";
    m_MaPresentation->demanderChangerVitesse();
}

void lecteurVue::demanderChangerModeAutomatique(){
    qDebug() << "Le mode change en automatique";
    m_MaPresentation->demanderChangerModeAutomatique();
}

void lecteurVue::demanderChangerModeManuel(){
    qDebug() << "Le mode change en manuel";
    m_MaPresentation->demanderChangerModeManuel();
}

void lecteurVue::demanderChargerDiapo(){
    qDebug() << "On charges une nouvelle diapo";
    m_MaPresentation->demanderChargerDiapo();
}

void lecteurVue::demanderEnleverDiapo(){
    qDebug() << "On retire le diapo";
    m_MaPresentation->demanderEnleverDiapo();
}

void lecteurVue::quitterApplication() {
    QApplication::quit();
}

void lecteurVue::demanderAPropos(){
    qDebug() << "On affiche la fenêtre à propos";
    m_MaPresentation->demanderAPropos();
}
