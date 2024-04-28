#ifndef LECTEUR_H
#define LECTEUR_H

#include <vector>
#include "diaporama.h"
using namespace std;


typedef vector<Diaporama> Diaporamas;

class Image;

class Lecteur
{
private:
    Diaporamas _allDiapos;
    unsigned int _numDiapoCourant;


public:
    // Les constructeurs
    Lecteur(); // Par défaut
    Lecteur(Diaporamas, unsigned int); // Avec le diaporama et l'indice


    // Les getters
    Diaporamas getAllDiapos() const;
    Diaporama& getDiapoCourant();
    unsigned int getNumDiapoCourant() const;
    unsigned int getNombreDiapos() const;

    // Les setters
    void setAllDiapos(const Diaporamas&);
    void setNumDiapoCourant(unsigned int);

    // Sous-programmes
    void declencherAction(char);
    void saisieVerifChoixActionSurImageCourante(char&);
    unsigned int saisieVerifChoixDiaporama();
    void charger(Images&);
    void chargerDiapos(Images);
    void afficherDiapoCourant();
};



#endif // LECTEUR_H
