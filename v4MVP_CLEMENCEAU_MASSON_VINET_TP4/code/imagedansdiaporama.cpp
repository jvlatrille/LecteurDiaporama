#include "imageDansDiaporama.h"

ImageDansDiaporama::ImageDansDiaporama(unsigned int pRangDansDiaporama, string pCategorie, string pTitre, string pChemin)
{
    rangDansDiaporama = pRangDansDiaporama;
    categorie = pCategorie;
    titre = pTitre;
    chemin = pChemin;
}

ImageDansDiaporama::~ImageDansDiaporama()
{}

unsigned int ImageDansDiaporama::getRangDansDiaporama() const
{
    return rangDansDiaporama;
}

string ImageDansDiaporama::getCategorie() const
{
    return categorie;
}

string ImageDansDiaporama::getTitre() const
{
    return titre;
}

string ImageDansDiaporama::getChemin() const
{
    return chemin;
}

void ImageDansDiaporama::afficher()
{
    cout << "image( rang:" << getRangDansDiaporama() << ", titre:" << getTitre() << ", categorie:"
         << getCategorie() << ", chemin:"<< getChemin() << ")" << endl;
}

void ImageDansDiaporama::setRangDansDiaporama(unsigned int pRangDansDiaporama)
{
    rangDansDiaporama = pRangDansDiaporama;
}

void ImageDansDiaporama::setTitre(string pTitre)
{
    titre = pTitre;
}

void ImageDansDiaporama::setCategorie(string pCategorie)
{
    categorie = pCategorie;
}

void ImageDansDiaporama::setChemin(string pChemin)
{
    chemin = pChemin;
}
