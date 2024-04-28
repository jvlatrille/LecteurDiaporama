#ifndef IMAGEDANSDIAPORAMA_H
#define IMAGEDANSDIAPORAMA_H

#include "image.h"
#include <vector>

// Types et classes nécessaires
typedef vector<Image> Images;

class imageDansDiaporama : public Image
{   
private:
    unsigned int _rang; // Rang de l'image dans le tableau d'images
    unsigned int _pos; // Position de l'image dans le diaporama

public:
    // Les constructeurs
    imageDansDiaporama();
    imageDansDiaporama(const Image&, unsigned int, unsigned int);
    imageDansDiaporama(Images&, unsigned int, unsigned int);

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
