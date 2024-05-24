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
    QObject::connect(ui->bSuivant, &QPushButton::clicked, this, [this]() {
        this->demanderAvancer();
        this->m_MaPresentation->demanderChangerModeManuel();
    });
    QObject::connect(ui->bPrecedent, &QPushButton::clicked, this, [this]() {
        this->demanderReculer();
        this->m_MaPresentation->demanderChangerModeManuel();
    });

    QObject::connect(ui->bLancerDiapo, &QPushButton::clicked, this, [this](){
        this->demanderChangerModeAutomatique();
    });

    QObject::connect(ui->bArret, &QPushButton::clicked,this,[this](){
        this->demanderChangerModeManuel();
    });


    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(quitterApplication()));


    // Connexions pour les actions du menu
    QObject::connect(ui->actionChargerDiapo, SIGNAL(triggered()), this, SLOT(demanderChargerDiapo()));
    QObject::connect(ui->actionEnleverDiapo, SIGNAL(triggered()), this, SLOT(demanderEnleverDiapo()));
    QObject::connect(ui->actionVitesseDefilement, SIGNAL(triggered()), this, SLOT(demanderChangerVitesse()));

    QObject::connect(ui->actionAPropos, SIGNAL(triggered()), this, SLOT(demanderAPropos()));

    // navigation entre les bouton avec tab
    QWidget::setTabOrder(ui->bPrecedent, ui->bSuivant);
}



lecteurVue::~lecteurVue()
{
    delete ui;
}

Presentation *lecteurVue::getPresentation() const
{
    return m_MaPresentation;
}



void lecteurVue::majPresentation(const QString &titreDiapo, const QString &titreImage, const QString &categorie, const QString &rang, const QString &chemin) {
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
        bool connected = connect(m_MaPresentation->getModele(), &Modele::imageChange, this, &lecteurVue::majPresentation);
        qDebug() << "Connecté ? " << connected;
    }
}

