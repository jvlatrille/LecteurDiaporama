#include "lecteurvue.h"
#include "lecteur.h"
#include "ui_lecteurvue.h"
#include "presentation.h"

lecteurVue::lecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lecteurVue)
{
    ui->setupUi(this);

    // Lecteur
    l = new Lecteur();
    l->changerDiaporama(2,"Diapo de test",1);

    // Connexions pour les boutons
    QObject::connect(ui->bSuivant, SIGNAL(clicked()), this, SLOT(sl_suivant()));
    QObject::connect(ui->bPrecedent, SIGNAL(clicked()), this, SLOT(sl_precedent()));
    QObject::connect(ui->bPause, SIGNAL(clicked()), this, SLOT(sl_departArret()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(sl_quitter()));

    // Connexions pour les actions du menu
    QObject::connect(ui->actionChargerDiapo, SIGNAL(triggered()), this, SLOT(sl_chargerDiapo()));
    QObject::connect(ui->actionEnleverDiapo, SIGNAL(triggered()), this, SLOT(sl_enleverDiapo()));
    QObject::connect(ui->actionVitesseDefilement, SIGNAL(triggered()), this, SLOT(sl_vitesseDefilement()));
    QObject::connect(ui->actionAutomatique, SIGNAL(triggered()), this, SLOT(sl_modeAuto()));
    QObject::connect(ui->actionManuel, SIGNAL(triggered()), this, SLOT(sl_modeManuel()));
    QObject::connect(ui->actionAPropos, SIGNAL(triggered()), this, SLOT(sl_aPropos()));

    //navigation entre les bouton avec tab
    QWidget::setTabOrder(ui->bPrecedent, ui->bPause);
    QWidget::setTabOrder(ui->bPause, ui->bSuivant);
}

lecteurVue::~lecteurVue()
{
    delete ui;
}

void lecteurVue::sl_suivant()
{
    l->avancer();
    qDebug() << "Image suivante";
}

void lecteurVue::sl_precedent()
{
    qDebug() << "Image précédente";
}

void lecteurVue::sl_departArret()
{
    qDebug() << "Défilement mis en pause / relancé (coché ou non)";
}

void lecteurVue::sl_quitter()
{
    qDebug() << "Quitter";
}

void lecteurVue::sl_chargerDiapo()
{
    qDebug() << "Charger diapo";
}

void lecteurVue::sl_enleverDiapo()
{
    qDebug() << "Enlever diapo";
}

void lecteurVue::sl_vitesseDefilement()
{
    qDebug() << "Changement de la vitesse de défilement";
}

void lecteurVue::sl_modeAuto()
{
    qDebug() << "Mode de défilement automatique";
}

void lecteurVue::sl_modeManuel()
{
    qDebug() << "Mode de défilement manuel";
}

void lecteurVue::sl_aPropos()
{
    qDebug() << "À propos";
}
