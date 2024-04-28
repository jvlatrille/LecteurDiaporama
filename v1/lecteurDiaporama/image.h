#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
using namespace std;


class Image
{
private:
    string _titre; // intitulé de l'image
    string _categorie; // catégorie de l'image (personne, animal, objet)
    string _chemin;


public:
    // Les constructeurs
    Image(); // Par défaut
    Image(const Image&); // De copie
    Image(string, string, string); // Complet

    // Les getters
    string getTitre() const; // Get le titre
    string getChemin() const; // Get le chemin
    string getCategorie() const; // Get la categorie

    // Les setters
    void setTitre(string); // Set le titre
    void setChemin(string); // Set le chemin
    void setCategorie(string); // Set la categorie

    // Sous-programmes
    void afficher() const; // affiche tous les champs de l'image
};


#endif // IMAGE_H
