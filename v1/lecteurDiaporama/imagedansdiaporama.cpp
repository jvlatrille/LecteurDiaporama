#include "imagedansdiaporama.h"

/***********************
 *      METHODES
 **********************/


// Les constructeurs

imageDansDiaporama::imageDansDiaporama():
    Image(),
    _rang(0),
    _pos(0)
{}

imageDansDiaporama::imageDansDiaporama(const Image& img, unsigned int rang, unsigned int pos ):
    Image(img),
    _rang(rang),
    _pos(pos)
{}

imageDansDiaporama::imageDansDiaporama(Images& images, unsigned int pos, unsigned int rang):
    Image(images[pos]),
    _rang(rang),
    _pos(pos)
{}



// Les getters
unsigned int imageDansDiaporama::getRang() const
{
    return _rang;
}

unsigned int imageDansDiaporama::getPos() const
{
    return _pos;
}

const Image& imageDansDiaporama::getImage() const
{
    return *this;
}


// Les setters
void imageDansDiaporama::setRang(unsigned int rang)
{
    _rang = rang;
}

void imageDansDiaporama::setPos(unsigned int pos)
{
    _pos = pos;
}



// Sous-programme
void imageDansDiaporama::afficherImageCourante() const
{
    cout << getRang() << " : ";
    afficher();
}
