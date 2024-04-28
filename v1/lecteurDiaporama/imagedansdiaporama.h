#ifndef IMAGEDANSDIAPORAMA_H
#define IMAGEDANSDIAPORAMA_H

#include "image.h"
#include <vector>

// Création d'un alias Image pour le type vector
typedef vector<Image> Images;

class imageDansDiaporama : public Image
{   
private:
    unsigned int _rang; // Rang de l'image dans le tableau d'images
    unsigned int _pos; // Position de l'image dans le diaporama

public:
    // Les constructeurs
    imageDansDiaporama(); // Par défaut
    imageDansDiaporama(const Image&, unsigned int, unsigned int); // Avec une image const
    imageDansDiaporama(Images&, unsigned int, unsigned int); // Avec le vector

    // Les getters
    unsigned int getRang() const;
    unsigned int getPos() const;
    const Image& getImage() const;

    // Les setters
    void setRang(unsigned int);
    void setPos(unsigned int);

    // Sous-programmes
    void afficherImageCourante() const;

};

#endif // IMAGEDANSDIAPORAMA_H
