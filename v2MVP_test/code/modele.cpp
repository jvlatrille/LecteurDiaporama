#include "modele.h"

Modele::Modele() : m_vitesseDefilement(0), m_posImageCourante(0), m_posImage(0)
{

}

unsigned int Modele::getVitesseDefilement() const
{
    return m_vitesseDefilement;
}

unsigned int Modele::getPosImageCourante() const
{
    return m_posImageCourante;
}

Diaporama *Modele::getDiaporama() const
{
    // À implémenter
}

void Modele::setVitesseDefilement(unsigned int vitesse)
{
    m_vitesseDefilement = vitesse;
}

void Modele::setDiaporama(Diaporama *diaporama)
{
        m_diapo = diaporama;
}

void Modele::avancer()
{

}

void Modele::reculer()
{
    // À implémenter
}

void Modele::triCroissantRang()
{
    // À implémenter
}
