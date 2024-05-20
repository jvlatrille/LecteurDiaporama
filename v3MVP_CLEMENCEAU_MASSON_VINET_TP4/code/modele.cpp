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
    if (!lecteurVide())
    {
        if (getPosImageCourante() == nbImages()- 1)
        {
            setPosImageCourante(0);
        }
        else {
            setPosImageCourante(getPosImageCourante() + 1);
        }
    }
}

void Modele::reculer()
{/*
    if (!lecteurVide())
    {
        if (getPosImageCourante() == 0)
        {
            setPosImageCourante(nbImages()- 1);
        }
        else {
            setPosImageCourante(getPosImageCourante() - 1);
        }
    }*/
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
    // Créer une instance de la fenêtre à propos
    QDialog* aproposDialog = new QDialog();
    // Charger l'interface utilisateur depuis le fichier .ui
    Ui::apropos aproposUi; // Utiliser 'apropos' au lieu de 'AProposDialog'
    aproposUi.setupUi(aproposDialog);
    // Afficher la fenêtre à propos
    aproposDialog->exec();
    // Libérer la mémoire utilisée par la fenêtre après sa fermeture
    delete aproposDialog;
}

