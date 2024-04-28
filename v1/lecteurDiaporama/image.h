#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
using namespace std;

// Module de manipulation d'éléments de type Image

class Image
{
private:
    string _titre; // intitulé de l'image
    string _categorie; // catégorie de l'image (personne, animal, objet)
    string _chemin;


public:
    // Les constructeurs
    Image();
    Image(const Image&);
    Image(string, string, string);

    // Les getters
    string getCategorie() const; // Get la categorie
    string getTitre() const; // Get le titre
    string getChemin() const; // Get le chemin

    // Les setters
    void setCategorie(string); // Set la categorie
    void setTitre(string); // Set le titre
    void setChemin(string); // Set le chemin

    // Sous-programmes
    void afficher() const; // affiche tous les champs de l'image
};


#endif // IMAGE_H
