#include "ui_lecteurvue.h"
#include "presentation.h"

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

void lecteurVue::majPresentation(Diaporama *d)
{
    ui->titreDiapo->setText(QString::fromStdString(d->getTitre()));
    ImageDansDiaporama* imageCourante = d->getImageCourante();
    ui->titreImage->setText(QString::fromStdString(imageCourante->getTitre()));
    ui->categorieImage->setText(QString::fromStdString(imageCourante->getCategorie()));
    ui->rangImage->setText(QString::number(imageCourante->getRangDansDiaporama()));
    ui->imageDiapo->setPixmap(QPixmap(QString::fromStdString(imageCourante->getChemin())));
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
