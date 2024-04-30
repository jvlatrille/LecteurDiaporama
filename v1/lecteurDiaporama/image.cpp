#include "image.h"

// Les constructeurs

Image::Image(): // Constructeur par défaut
    d_titre(""),
    d_categorie(""),
    d_chemin("")
{}

Image::Image(const Image& origine): // Constructeur de copie
    d_titre(origine.getTitre()),
    d_categorie(origine.getCategorie()),
    d_chemin(origine.getChemin())
{}

Image::Image(string pCategorie, string pTitre, string pChemin): // Constructeur avec tout
    d_titre(pTitre),
    d_categorie(pCategorie),
    d_chemin(pChemin)
{}


// Les getters
string Image::getCategorie() const
{
    return d_categorie;
}

string Image::getTitre() const
{
    return d_titre;
}

string Image::getChemin() const
{
    return d_chemin;
}


// Les setters

void Image::setCategorie(string pCategorie)
{
    d_categorie = pCategorie;
}

void Image::setTitre(string pTitre)
{
    d_titre = pTitre;
}

void Image::setChemin(string pChemin)
{
    d_chemin = pChemin;
}


// Sous-programmes
void Image::afficher() const
{
    cout << "Image : titre: " << getTitre(); cout << ", categorie: "
         << getCategorie(); cout << ", chemin: "<< getChemin() << "" << endl;
}
