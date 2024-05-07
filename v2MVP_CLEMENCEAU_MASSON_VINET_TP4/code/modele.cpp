#include "modele.h"

Modele::Modele(QObject *parent)
    : QObject(parent), m_vitesseDefilement(1), m_posImageCourante(0)
{
}

std::string Modele::getTitre() const
{
    return m_titre;
}

unsigned int Modele::getVitesseDefilement() const
{
    return m_vitesseDefilement;
}

unsigned int Modele::getNombreImages() const
{
    return m_localisationImages.size();
}

unsigned int Modele::getPosImageCourante() const
{
    return m_posImageCourante;
}

void Modele::setTitre(const std::string& titre)
{
    m_titre = titre;
}

void Modele::setVitesseDefilement(unsigned int vitesseDefilement)
{
    m_vitesseDefilement = vitesseDefilement;
}

void Modele::setLocalisationImages(const std::vector<imageDansDiaporama>& localisationImages)
{
    m_localisationImages = localisationImages;
}

void Modele::setPosImageCourante(unsigned int posImageCourante)
{
    m_posImageCourante = posImageCourante;
}

void Modele::avancer()
{
    // Vérifier la postion actuelle (si c'est la dernière image du diaporama, on passe à l'indice 0 (la première))
    if (getPosImageCourante() == getNombreImages() - 1){
        setPosImageCourante(0);
    }
    else {
        setPosImageCourante(getPosImageCourante() + 1);
    }
}

void Modele::reculer()
{
    // Vérifier la postion actuelle (si c'est la première image du diaporama, on passe à l'indice -1 ( la dernière))
    if (getPosImageCourante() == 0){
        setPosImageCourante(getNombreImages() - 1);
    }
    else {
        setPosImageCourante(getPosImageCourante() - 1);
    }
}

void Modele::triCroissantRang(){
    unsigned int taille = m_localisationImages.size();

    // Parcourir le tableau jusqu'à ce qu'il n'y ait plus d'échanges à effectuer
    for (unsigned int i = 0; i < taille - 1; i++) {
        bool estEchange = false;

        // Parcourir le tableau à partir de la première image
        for (unsigned int j = 0; j < taille - i - 1; j++) {
            // Comparer le rang de l'image actuelle avec celui de l'image suivante
            if (this->m_localisationImages[j].getRang() > this->m_localisationImages[j + 1].getRang()) {
                // Échanger les deux images si elles ne sont pas dans le bon ordre
                swap(this->m_localisationImages[j], this->m_localisationImages[j + 1]);
                estEchange = true; // Indiquer qu'un échange a été effectué
            }
        }
        // Si aucun échange n'a été effectué pendant cette itération, le tableau est déjà trié
        if (!estEchange) {
            break;
        }
    }
}
