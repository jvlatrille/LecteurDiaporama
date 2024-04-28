#include "image.h"

Image::Image(string pCategorie, string pTitre, string pChemin):
    _categorie(pCategorie),
    _titre(pTitre),
    _chemin(pChemin){
}

string Image::getCategorie() const
{
    return this->_categorie;
}

string Image::getTitre() const
{
    return this->_titre;
}

string Image::getChemin() const
{
    return this->_chemin;
}

void Image::afficher() const
{
    cout << "image(titre:" << this->getTitre() << ", categorie:"
         << this->getCategorie() << ", chemin:"<< this->getChemin() << ")" << endl;
}
