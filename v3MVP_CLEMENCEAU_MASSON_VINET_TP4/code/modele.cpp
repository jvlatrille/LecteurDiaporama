#include "modele.h"
#include <QDialog>
#include "ui_apropos.h"


Modele::Modele()
{

}

unsigned int Modele::getVitesseDefilement() const
{
    return m_vitesseDefilement;
}

bool Modele::lecteurVide() const
{
    return (getDiaporama() == nullptr);
}

Lecteur* Modele::getLecteur() const
{
    return lecteur;
}

void Modele::setLecteur(Lecteur* newLecteur)
{
    lecteur = newLecteur;
}

unsigned int Modele::getPosImageCourante() const
{
    return m_posImageCourante;
}

unsigned int Modele::nbImages() const
{
    if (lecteurVide())
    {
        throw string ("lecteur vide");
    }
    return m_MonDiapo->nbImages();
}


Diaporama *Modele::getDiaporama() const
{
    return m_MonDiapo;
}


void Modele::setVitesseDefilement(unsigned int vitesse)
{
    m_vitesseDefilement = vitesse;
}

void Modele::setPosImageCourante(unsigned int pPosImageCourante)
{
    m_posImageCourante = pPosImageCourante;
}


void Modele::setDiaporama(Diaporama *diaporama)
{
        m_MonDiapo = diaporama;
}

void Modele::avancer()
{
    qDebug()<< "J'avance 1";
    lecteur->avancer();
    qDebug()<< "J'avance 2";
}

void Modele::reculer()
{
    lecteur->reculer();
}


void Modele::etatAutomatique()
{
    _etat = UnEtat::automatique;
}

void Modele::etatManuel()
{
    _etat = UnEtat::manuel;
}


void Modele::triCroissantRang()
{
    ImageDansDiaporama* pteurImage;
    unsigned int taille = nbImages();
    for (unsigned int ici = taille-1; ici >=1 ; ici--)
    {
        // faire monter la bulle ici = déplacer l'élément de rang le plus grand en position ici
        // par échanges successifs
        for (unsigned int i = 0; i < ici; i++)
        {
            if (images[i]->getRangDansDiaporama() > images[i+1]->getRangDansDiaporama())
            {
                // echanger les 2 éléments
                pteurImage = images[i];
                images[i] = images[i+1];
                images[i+1] = pteurImage;
            }
        }
    }
}

Modele::UnEtat Modele::getEtat() const {
    return _etat;
}

void Modele::departArretAuto() {
    // Implémentation du départ/arrêt automatique
}

void Modele::changerVitesse() {
    // Implémentation du changement de vitesse
}

void Modele::chargerDiapo() {
    // Implémentation du chargement de diaporama
}

void Modele::enleverDiapo() {
    // Implémentation de l'enlèvement de diaporama
}

void Modele::aPropos() {
    QDialog* aproposDialog = new QDialog();
    Ui::apropos aproposUi;
    aproposUi.setupUi(aproposDialog);
    aproposDialog->exec();
    delete aproposDialog;
}

