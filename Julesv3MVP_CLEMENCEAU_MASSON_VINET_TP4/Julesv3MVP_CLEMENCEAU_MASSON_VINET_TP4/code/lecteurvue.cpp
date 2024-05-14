#include "lecteurvue.h"
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
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(demanderQuitter()));

    // Connexions pour les actions du menu
    QObject::connect(ui->actionChargerDiapo, SIGNAL(triggered()), this, SLOT(sl_chargerDiapo()));
    QObject::connect(ui->actionEnleverDiapo, SIGNAL(triggered()), this, SLOT(sl_enleverDiapo()));
    QObject::connect(ui->actionVitesseDefilement, SIGNAL(triggered()), this, SLOT(demanderEnleverDiapo()));
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

Presentation *lecteurVue::getPresentation() const
{
    return m_MaPresentation;
}

void lecteurVue::setPresentation(Presentation * p)
{
    m_MaPresentation = p;
}


void lecteurVue::sl_suivant()
{
    qDebug() << "Image suivante";
}

void lecteurVue::sl_precedent()
{
    qDebug() << "Image précédente";
}

void lecteurVue::sl_pause()
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
