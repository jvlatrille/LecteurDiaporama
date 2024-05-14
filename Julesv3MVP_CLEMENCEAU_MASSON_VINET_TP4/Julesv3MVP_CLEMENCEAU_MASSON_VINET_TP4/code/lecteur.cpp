#include "lecteur.h"
#include "lecteurvue.h"
#include <QDebug>

Lecteur::Lecteur() : idDiaporama(0), diaporama(nullptr)
{
}

Lecteur::~Lecteur()
{
    if (getDiaporama() != nullptr)
    {
        viderLecteur();
        delete diaporama;
    }
}

unsigned int Lecteur::getIdDiaporama() const
{
    return idDiaporama; // valeur >= 0
}

Diaporama* Lecteur::getDiaporama() const
{
    return diaporama;   // peut être nullptr
}

unsigned int Lecteur::getPosImageCourante() const
{
    if (lecteurVide() ||
        (!lecteurVide() && nbImages() == 0 ))
    {
        throw string ("pas d'image courante : lecteur vide ou diaporama vide");
    }
    return posImageCourante;
}

bool Lecteur::lecteurVide() const
{
    return (getDiaporama() == nullptr);
}

ImageDansDiaporama *Lecteur::getImageCourante() const
{
    if (lecteurVide() ||
        (!lecteurVide() && nbImages() == 0 ))
    {
        return nullptr;
    }

    return diaporama->getImages().at(getPosImageCourante());
}


unsigned int Lecteur::nbImages() const
{
    if (lecteurVide())
    {
        throw string ("lecteur vide");
    }
    return diaporama->nbImages();
}

void Lecteur::afficher()
{
    /* affichen selon le cas :
     * - lecteur vide
     * ou bien
     * - le numéro de diaporama affiché
     * - et l'image courante ou bien 'diaporama vide' */

    string info;
    if (lecteurVide())
    {
        info = "Lecteur vide = pas de diaporama charge ";
        cout << info << endl;
    }

    else
    {
        info = "Diaporama num. " + std::to_string(getIdDiaporama()) + " - "  + getDiaporama()->getTitre() + "\n";

        // Afficher l'image courante du diaporama chargé
        if (nbImages() == 0)
        {
            info.append("Diaporama vide \n");
            cout << info;
        }
        else
        {
            info.append(std::to_string(diaporama->getImages()[posImageCourante]->getRangDansDiaporama()));
            info.append(" sur ");
            info.append((std::to_string(diaporama->getImages().size())));
            info.append(" / ");
            cout << info;
            diaporama->getImages()[posImageCourante]->afficher();
        }
    }
}

void Lecteur::setIdDiaporama(unsigned int pIdDiaporama)
{
    idDiaporama = pIdDiaporama;
}

void Lecteur::setDiaporama(Diaporama* pDiaporama)
{
    diaporama = pDiaporama;
}

void Lecteur::setPosImageCourante(unsigned int pPosImageCourante)
{
    posImageCourante = pPosImageCourante;
}

void Lecteur::changerDiaporama(unsigned int pId, string pTitre, unsigned int pVitesse)
{
    /* Chargement des informations et images images associées au diaporama courant
       Dans une version ultérieure, le seul paramètre sera le numéro ou identifiant du diaporama choisi,
       les autres informations proviendront de la Base de Données */

    if (pId != 0)
    {
        if (!lecteurVide())
        {
            diaporama->vider();
        }
        else
        {
            diaporama = new Diaporama();
        }
        setIdDiaporama(pId);
        diaporama->setId(pId);
        diaporama->setTitre(pTitre);
        diaporama->setVitesseDefilement(pVitesse);
        chargerDiaporamaCourant(); // charge les images et la position de l'image courante
    }
    else
        if (!lecteurVide())
        {
            viderLecteur();
        }
}

void Lecteur::viderLecteur()
{
    // supprime les images du diaporama,  et réinitialise les attributs du lecteur
    if (!lecteurVide())
    {
        diaporama->vider();
        setDiaporama(nullptr);
        setIdDiaporama(0);
    }
}


void Lecteur::avancer()
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

void Lecteur::reculer()
{
    if (!lecteurVide())
    {
        if (getPosImageCourante() == 0)
        {
            setPosImageCourante(nbImages()- 1);
        }
        else {
            setPosImageCourante(getPosImageCourante() - 1);
        }
    }
}

void Lecteur::chargerDiaporamaCourant()
{
    /* Chargement des images associées au diaporama courant */
    diaporama->charger();
    if (nbImages() != 0)
    { setPosImageCourante(0) ;}
}



void Lecteur::departArretAuto()
{
    qDebug() << "Demande à arrêter / démarer diapo (en fonction de l'etat)";
}


void Lecteur::changerVitesse()
{
    qDebug() << "Demande à changer la vitesse";
}

void Lecteur::changerModeAutomatique()
{
    qDebug() << "Demande à changer de mode en automatique";
}

void Lecteur::changerModeManuel()
{
    qDebug() << "Demande à changer de mode en Manuel";
}

void Lecteur::chargerDiapo()
{
    qDebug() << "Demande à charger un nouveau diaporama";
}

void Lecteur::quitter()
{
    qDebug() << "Demande à quitter l'application";
}

void Lecteur::enleverDiapo()
{
    qDebug() << "Demande à enlever le diaporama courrant";
}

void Lecteur::ouvrirAPropos()
{
    qDebug() << "Demande à afficher la page a propos de l'application";
}

