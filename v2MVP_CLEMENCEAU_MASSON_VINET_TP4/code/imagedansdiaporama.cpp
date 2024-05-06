#include "imagedansdiaporama.h"

/***********************
 *      METHODES
 **********************/


// Les constructeurs
imageDansDiaporama::imageDansDiaporama():
    Image(),
    m_rang(0),
    m_pos(0)
{}

imageDansDiaporama::imageDansDiaporama(const Image& img, unsigned int rang, unsigned int pos ):
    Image(img),
    m_rang(rang),
    m_pos(pos)
{}

imageDansDiaporama::imageDansDiaporama(Images& images, unsigned int pos, unsigned int rang):
    Image(images[pos]),
    m_rang(rang),
    m_pos(pos)
{}



// Les getters
unsigned int imageDansDiaporama::getRang() const
{
    return m_rang;
}

unsigned int imageDansDiaporama::getPos() const
{
    return m_pos;
}

const Image& imageDansDiaporama::getImage() const
{
    return *this;
}


// Les setters
void imageDansDiaporama::setRang(unsigned int rang)
{
    m_rang = rang;
}

void imageDansDiaporama::setPos(unsigned int pos)
{
    m_pos = pos;
}



// Sous-programme
void imageDansDiaporama::afficherImageCourante() const
{
    cout << getRang() << " : ";
    afficher();
}
