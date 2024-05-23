#include "ui_lecteurvue.h"
#include "presentation.h"
#include <QImage>

lecteurVue::lecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lecteurVue)
    , m_MaPresentation(new Presentation())
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
    QObject::connect(ui->actionAPropos, SIGNAL(triggered()), this, SLOT(demanderAPropos()));

    // navigation entre les bouton avec tab
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



void lecteurVue::majPresentation(Diaporama *d, Modele::UnEtat etat)
{
    qDebug() << "Maj Presentation commence";
    ui->titreDiapo->setText(QString::fromStdString(d->getTitre()));
    ImageDansDiaporama* imageCourante = d->getImageCourante();
    ui->titreImage->setText(QString::fromStdString(imageCourante->getTitre()));
    ui->categorieImage->setText(QString::fromStdString(imageCourante->getCategorie()));
    ui->rangImage->setText(QString::number(imageCourante->getRangDansDiaporama()));
    ui->imageDiapo->setPixmap(QPixmap(QString::fromStdString(imageCourante->getChemin())));
    qDebug() << "Position image courante : " << d->getPosImageCourante();
    if (d->nbImages() > 0)
    {
        ui->bPrecedent->setEnabled(true);
        ui->bSuivant->setEnabled(true);
    }
    else
    {
        ui->bPrecedent->setDisabled(true);
        ui->bSuivant->setDisabled(true);
    }

}


void lecteurVue::majPresentationSlot(const QString &titreDiapo, const QString &titreImage, const QString &categorie, const QString &rang, const QString &chemin) {
    qDebug() << "Émission de imageChange avec: " << titreDiapo << titreImage << categorie << rang << chemin;
    ui->titreDiapo->setText(titreDiapo);
    ui->titreImage->setText(titreImage);
    ui->categorieImage->setText(categorie);
    ui->rangImage->setText(rang);
    ui->imageDiapo->setPixmap(QPixmap(chemin));

    ui->imageDiapo->repaint();
}


void lecteurVue::setPresentation(Presentation * p)
{
    m_MaPresentation = p;
    //majPresentation(getPresentation()->getDiapoActuel()); fait planter le prog
}



void lecteurVue::demanderAvancer(){
    qDebug() << "Demande d'avancer";
    m_MaPresentation->demanderAvancer();
}

void lecteurVue::demanderReculer(){
    qDebug() << "Demande à reculer";
    m_MaPresentation->demanderReculer();
}

void lecteurVue::demanderDepartArretAuto(){
    qDebug() << "Demande à arrêter / démarer diapo (en fonction de l'etat)";
    m_MaPresentation->demanderDepartArretAuto();
}

void lecteurVue::demanderChangerVitesse(){
    qDebug() << "Demande à changer la vitesse";
    m_MaPresentation->demanderChangerVitesse();
}

void lecteurVue::demanderChangerModeAutomatique(){
    qDebug() << "Demande à changer de mode en automatique";
    m_MaPresentation->demanderChangerModeAutomatique();
}

void lecteurVue::demanderChangerModeManuel(){
    qDebug() << "Demande à changer de mode en Manuel";
    m_MaPresentation->demanderChangerModeManuel();
}

void lecteurVue::demanderChargerDiapo(){
    qDebug() << "Demande à charger un nouveau diaporama";
    m_MaPresentation->demanderChargerDiapo();
}

void lecteurVue::demanderEnleverDiapo(){
    qDebug() << "Demande à enlever le diaporama courrant";
    m_MaPresentation->demanderEnleverDiapo();
}

void lecteurVue::quitterApplication() {
    QApplication::quit();
}

void lecteurVue::demanderAPropos(){
    qDebug() << "On affiche la fenêtre à propos";
    m_MaPresentation->demanderAPropos();
}


void lecteurVue::initializeConnections() {
    if (m_MaPresentation && m_MaPresentation->getModele()) {
        bool connected = connect(m_MaPresentation->getModele(), &Modele::imageChange, this, &lecteurVue::majPresentationSlot);
        qDebug() << "Connecté ? " << connected;
    }
}

