#ifndef DIAPORAMA_H
#define DIAPORAMA_H

#include <vector>
#include "imagedansdiaporama.h"

// Création d'un alias ImagesDuDiaporama pour le type vector
typedef vector<imageDansDiaporama> ImagesDuDiaporama;

class Diaporama {
private:
    // Attributs
    string m_titre;
    ImagesDuDiaporama m_localisationImages; // Chemin d'accès de l'image
    unsigned int m_vitesseDefilement;
    unsigned int m_posImageCourante;

public:
    // Les constructeurs
    Diaporama(); // Par défaut
    Diaporama(string, unsigned int = 1, ImagesDuDiaporama = {}, unsigned int = 0);
    Diaporama(string, unsigned int, unsigned int);

    // Les getters
    string getTitre()const;
    ImagesDuDiaporama getLocalisationImages() const;
    unsigned int getVitesseDefilement() const;
    unsigned int getNombreImages() const;
    unsigned int getPosImageCourante() const;
    imageDansDiaporama getImageCourante() const;

    // Les setters
    void setTitre(const string&);
    void setVitesseDefilement(unsigned int);
    void setLocalisationImages(const ImagesDuDiaporama&);
    void setPosImageCourante(unsigned int);

    // Sous-programmes
    void ajouterImage(const imageDansDiaporama&);
    void avancer();
    void reculer();
    void afficherImageCouranteDansDiaporamaCourant () const;
    void triCroissantRang ();
};


#endif // DIAPORAMA_H
