#include "lecteurdiaporama.h"
#include "ui_lecteurdiaporama.h"

lecteurDiaporama::lecteurDiaporama(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lecteurDiaporama)
{
    ui->setupUi(this);

    // Connexions pour les boutons
    QObject::connect(ui->bSuivant, SIGNAL(clicked()), this, SLOT(sl_suivant()));
    QObject::connect(ui->bPrecedent, SIGNAL(clicked()), this, SLOT(sl_precedent()));
    QObject::connect(ui->bPause, SIGNAL(clicked()), this, SLOT(sl_pause()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(sl_quitter()));

    // Connexions pour les actions du menu
    QObject::connect(ui->actionChargerDiapo, SIGNAL(triggered()), this, SLOT(sl_chargerDiapo()));
    QObject::connect(ui->actionEnleverDiapo, SIGNAL(triggered()), this, SLOT(sl_enleverDipo()));
    QObject::connect(ui->actionVitesseDefilement, SIGNAL(triggered()), this, SLOT(sl_vitesseDefilement()));
    QObject::connect(ui->actionAutomatique, SIGNAL(triggered()), this, SLOT(sl_modeAuto()));
    QObject::connect(ui->actionManuel, SIGNAL(triggered()), this, SLOT(sl_modeManuel()));
    QObject::connect(ui->actionAPropos, SIGNAL(triggered()), this, SLOT(sl_aPropos()));

    //navigation entre les bouton avec tab
    QWidget::setTabOrder(ui->bPrecedent, ui->bPause);
    QWidget::setTabOrder(ui->bPause, ui->bSuivant);
}

lecteurDiaporama::~lecteurDiaporama()
{
    delete ui;
}

void lecteurDiaporama::sl_suivant()
{
    qDebug() << "Image suivante";
}

void lecteurDiaporama::sl_precedent()
{
    qDebug() << "Image précédente";
}

void lecteurDiaporama::sl_pause()
{
    qDebug() << "Défilement mis en pause / relancé (coché ou non)";
}

void lecteurDiaporama::sl_quitter()
{
    qDebug() << "Quitter";
}

void lecteurDiaporama::sl_chargerDiapo()
{
    qDebug() << "Charger diapo";
}

void lecteurDiaporama::sl_enleverDipo()
{
    qDebug() << "Enlever diapo";
}

void lecteurDiaporama::sl_vitesseDefilement()
{
    qDebug() << "Changement de la vitesse de défilement";
}

void lecteurDiaporama::sl_modeAuto()
{
    qDebug() << "Mode de défilement automatique";
}

void lecteurDiaporama::sl_modeManuel()
{
    qDebug() << "Mode de défilement manuel";
}

void lecteurDiaporama::sl_aPropos()
{
    qDebug() << "À propos";
}
