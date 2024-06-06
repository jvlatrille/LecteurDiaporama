#include "imageDansDiaporama.h"

ImageDansDiaporama::ImageDansDiaporama(unsigned int pRangDansDiaporama, string pCategorie, string pTitre, string pChemin)
{
    rangDansDiaporama = pRangDansDiaporama; // Initialiser le rang dans le diaporama
    categorie = pCategorie; // Initialiser la catégorie de l'image
    titre = pTitre; // Initialiser le titre de l'image
    chemin = pChemin; // Initialiser le chemin de l'image
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
