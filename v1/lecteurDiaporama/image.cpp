#include "image.h"

// Les constructeurs

Image::Image(): // Constructeur par défaut
    _titre(""),
    _categorie(""),
    _chemin("")
{}

Image::Image(const Image& origine): // Constructeur de copie
    _titre(origine.getTitre()),
    _categorie(origine.getCategorie()),
    _chemin(origine.getChemin())
{}

Image::Image(string pCategorie, string pTitre, string pChemin): // Constructeur avec tout
    _titre(pTitre),
    _categorie(pCategorie),
    _chemin(pChemin)
{}


// Les getters
string Image::getCategorie() const
{
    return _categorie;
}

string Image::getTitre() const
{
    return _titre;
}

string Image::getChemin() const
{
    return _chemin;
}


// Les setters

void Image::setCategorie(string pCategorie)
{
    _categorie = pCategorie;
}

void Image::setTitre(string pTitre)
{
    _titre = pTitre;
}

void Image::setChemin(string pChemin)
{
    _chemin = pChemin;
}


// Sous-programmes
void Image::afficher() const
{
    cout << "Image : titre: " << getTitre(); cout << ", categorie: "
         << getCategorie(); cout << ", chemin: "<< getChemin() << "" << endl;
}
