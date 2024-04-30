#include "imagedansdiaporama.h"

/***********************
 *      METHODES
 **********************/


// Les constructeurs
imageDansDiaporama::imageDansDiaporama():
    Image(),
    d_rang(0),
    d_pos(0)
{}

imageDansDiaporama::imageDansDiaporama(const Image& img, unsigned int rang, unsigned int pos ):
    Image(img),
    d_rang(rang),
    d_pos(pos)
{}

imageDansDiaporama::imageDansDiaporama(Images& images, unsigned int pos, unsigned int rang):
    Image(images[pos]),
    d_rang(rang),
    d_pos(pos)
{}



// Les getters
unsigned int imageDansDiaporama::getRang() const
{
    return d_rang;
}

unsigned int imageDansDiaporama::getPos() const
{
    return d_pos;
}

const Image& imageDansDiaporama::getImage() const
{
    return *this;
}


// Les setters
void imageDansDiaporama::setRang(unsigned int rang)
{
    d_rang = rang;
}

void imageDansDiaporama::setPos(unsigned int pos)
{
    d_pos = pos;
}



// Sous-programme
void imageDansDiaporama::afficherImageCourante() const
{
    cout << getRang() << " : ";
    afficher();
}
