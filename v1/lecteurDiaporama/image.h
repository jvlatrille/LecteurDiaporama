#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
using namespace std;

// Module de manipulation d'éléments de type Image

class Image
{
private:
    string _titre;              // intitulé de l'image
    string _categorie;          // catégorie de l'image (personne, animal, objet)
    string _chemin;


public:
    Image(string pTitre="", string pCategorie="", string pChemin = "");
    ~Image();
    getCategorie() const; // Get la categorie
    getTitre() const; // Get le titre
    getChemin() const; // Get le chemin
    afficher() const; // affiche tous les champs de l'image
};

#endif // IMAGE_H
