#include "image.h"

// Les constructeurs

Image::Image(): // Constructeur par défaut
    m_titre(""),
    m_categorie(""),
    m_chemin("")
{}

Image::Image(const Image& origine): // Constructeur de copie
    m_titre(origine.getTitre()),
    m_categorie(origine.getCategorie()),
    m_chemin(origine.getChemin())
{}

Image::Image(string pCategorie, string pTitre, string pChemin): // Constructeur avec tout
    m_titre(pTitre),
    m_categorie(pCategorie),
    m_chemin(pChemin)
{}


// Les getters
string Image::getCategorie() const
{
    return m_categorie;
}

string Image::getTitre() const
{
    return m_titre;
}

string Image::getChemin() const
{
    return m_chemin;
}


// Les setters

void Image::setCategorie(string pCategorie)
{
    m_categorie = pCategorie;
}

void Image::setTitre(string pTitre)
{
    m_titre = pTitre;
}

void Image::setChemin(string pChemin)
{
    m_chemin = pChemin;
}


// Sous-programmes
void Image::afficher() const
{
    cout << "Image : titre: " << getTitre(); cout << ", categorie: "
         << getCategorie(); cout << ", chemin: "<< getChemin() << "" << endl;
}
