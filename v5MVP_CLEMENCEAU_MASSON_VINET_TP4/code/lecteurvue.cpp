#include "ui_lecteurvue.h"
#include "presentation.h"
#include "apropos.h"
#include "vit.h"
#include "charger.h"
#include <QImage>

lecteurVue::lecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lecteurVue)
    , m_MaPresentation(new Presentation())
{
    ui->setupUi(this);

     setWindowTitle("S2.01 - Lecteur de diaporama");

    // Connexions pour les boutons
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(quitterApplication()));


    // Connexions pour les actions du menu
    QObject::connect(ui->actionChargerDiapo, SIGNAL(triggered()), this, SLOT(demanderChargerDiapo()));
    QObject::connect(ui->actionEnleverDiapo, SIGNAL(triggered()), this, SLOT(demanderEnleverDiapo()));
    QObject::connect(ui->actionVitesseDefilement, SIGNAL(triggered()), this, SLOT(demanderChangerVitesse()));

    QObject::connect(ui->actionAPropos, SIGNAL(triggered()), this, SLOT(demanderAPropos()));


    QObject::connect(ui->bSuivant, SIGNAL(clicked()), this, SLOT(demanderAvancer()));
    QObject::connect(ui->bPrecedent, SIGNAL(clicked()), this, SLOT(demanderReculer()));
    QObject::connect(ui->bLancerDiapo, SIGNAL(clicked()), this, SLOT(demanderChangerModeAutomatique()));
    QObject::connect(ui->bArret,SIGNAL(clicked()),this,SLOT(demanderChangerModeManuel()));

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

    getPresentation()->demanderAvancer();
}

void lecteurVue::demanderReculer(){
    qDebug() << "Demande à reculer";
    getPresentation()->demanderReculer();
}


void lecteurVue::demanderChangerVitesse(){
    qDebug() << "Demande à changer la vitesse";
    vit* fenetreV = new vit();
    qDebug() << "Dans la vue*****";
    reponse = fenetreV->exec();
    if(reponse == 1){
    qDebug() << "On affiche la fenêtre vitesse";
    getPresentation()->demanderChangerVitesse(fenetreV);
    }
    delete fenetreV;
}

void lecteurVue::demanderChangerModeAutomatique(){
    qDebug() << "Demande à changer de mode en automatique";
    getPresentation()->demanderChangerModeAutomatique();
}

void lecteurVue::demanderChangerModeManuel(){
    qDebug() << "Demande à changer de mode en Manuel";
    getPresentation()->demanderChangerModeManuel();
}

void lecteurVue::demanderChargerDiapo(){
    qDebug() << "Demande à charger un nouveau diaporama";
    charger fenetreCharger;

    Diaporamas diaporamas;
    listeDiaporamas(diaporamas);

    fenetreCharger.updateDiaporamas(diaporamas);
    connect(&fenetreCharger, &charger::diaporamaSelectionne, this, &lecteurVue::recevoirDiaporamaSelectionne);
    fenetreCharger.exec();

}

void lecteurVue::recevoirDiaporamaSelectionne(unsigned int diaporamaId){
    listeDiaporamas(this->diaporamas);
    for (const InfosDiaporama& diapo : diaporamas) {
        if (diapo.id == diaporamaId) {
            qDebug() << "ID:" << diapo.id << ", Titre:" << QString::fromStdString(diapo.titre) << ", Vitesse de défilement:" << diapo.vitesseDefilement;
            getPresentation()->demanderChargerDiapo(diapo.id, QString::fromStdString(diapo.titre), diapo.vitesseDefilement);
        }
    }
    qDebug() << "Diaporama avec l'ID" << diaporamaId << "non trouvé.";
}

void lecteurVue::listeDiaporamas(Diaporamas &diaporamas) {
    InfosDiaporama diapo;
    // Diaporama de Pantxika
    diapo.id = 1;
    diapo.titre = "Diaporama Pantxika";
    diapo.vitesseDefilement = 2;
    diaporamas.push_back(diapo);

     // Diaporama de Thierry
    diapo.id = 2;
    diapo.titre = "Diaporama Thierry";
    diapo.vitesseDefilement = 4;
    diaporamas.push_back(diapo);

     // Diaporama de Yann
    diapo.id = 3;
    diapo.titre = "Diaporama Yann";
    diapo.vitesseDefilement = 2;
    diaporamas.push_back(diapo);

     // Diaporama de Manu
    diapo.id = 4;
    diapo.titre = "Diaporama Manu";
    diapo.vitesseDefilement = 1;
    diaporamas.push_back(diapo);
}

void lecteurVue::demanderEnleverDiapo(){
    qDebug() << "Demande à enlever le diaporama courrant";
    getPresentation()->demanderEnleverDiapo();
}


void lecteurVue::quitterApplication() {
    QApplication::quit();
}

void lecteurVue::demanderAPropos(){
    qDebug() << "On affiche la fenêtre à propos";
    apropos* fenetreAPropos = new apropos();
    fenetreAPropos->exec();
    delete fenetreAPropos;
}


void lecteurVue::initializeConnections() {
    if (getPresentation() && getPresentation()->getModele()) {
        bool connected = connect(m_MaPresentation->getModele(), &Modele::imageChange, this, &lecteurVue::majPresentation);
        qDebug() << "Connecté ? " << connected;
    }
}

void lecteurVue::majInterface(Modele::UnEtat e)
{
    switch(e)
    {
        case Modele::defaut:
            // Maj des boutons
            ui->actionAutomatique->setEnabled(false);
            ui->actionManuel->setEnabled(false);
            ui->bPrecedent->setEnabled(false);
            ui->bSuivant->setEnabled(false);
            ui->bLancerDiapo->setEnabled(false);
            ui->bArret->setEnabled(false);
            ui->actionEnleverDiapo->setEnabled(false);
            ui->actionVitesseDefilement->setEnabled(false);
            ui->titreDiapo->setText("Titre du diaporama");
            ui->titreImage->setText("Titre de l'image");
            ui->categorieImage->setText("Categorie de l'image");
            ui->rangImage->setText("Rang de l'image");
            ui->imageDiapo->setPixmap(QString("Veuillez choisir un diaporama"));
            ui->mode->setText("Mode : défaut");
            break;
        case Modele::manuel:
            // Maj des boutons
            ui->actionManuel->setEnabled(false);
            ui->actionAutomatique->setEnabled(true);
            ui->actionVitesseDefilement->setEnabled(true);
            ui->bPrecedent->setEnabled(true);
            ui->bSuivant->setEnabled(true);
            ui->bLancerDiapo->setEnabled(true);
            ui->bArret->setEnabled(false);
            ui->actionEnleverDiapo->setEnabled(true);
            ui->mode->setText("Mode : manuel");
            break;
        case Modele::automatique:
            // Maj des boutons
            ui->actionAutomatique->setEnabled(false);
            ui->actionManuel->setEnabled(true);
            ui->actionVitesseDefilement->setEnabled(false);
            ui->bPrecedent->setEnabled(true);
            ui->bSuivant->setEnabled(true);
            ui->bLancerDiapo->setEnabled(false);
            ui->bArret->setEnabled(true);
            ui->actionEnleverDiapo->setEnabled(false);
            ui->mode->setText("Mode : automatique");
            break;
    }
}
