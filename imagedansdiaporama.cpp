#include "imagedansdiaporama.h"

/***********************
 *      METHODES
 **********************/


/*** Constructeurs ***/

imageDansDiaporama::imageDansDiaporama():
    Image(),
    _rang(0),
    _pos(0){}

imageDansDiaporama::imageDansDiaporama(const Image& img, unsigned int rang, unsigned int pos ):
    Image(img),
    _rang(rang),
    _pos(pos){}

imageDansDiaporama::imageDansDiaporama(Images& images, unsigned int pos, unsigned int rang):
    Image(images[pos]),
    _rang(rang),
    _pos(pos) {}



/*** Getters ***/
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


/*** Setters ***/
void imageDansDiaporama::setRang(unsigned int rang)
{
    _rang = rang;
}

void imageDansDiaporama::setPos(unsigned int pos)
{
    _pos = pos;
}



/*** Autres méthodes ***/
void imageDansDiaporama::afficherImageCourante() const
{
    cout << getRang() << " : ";
    afficher();
}
