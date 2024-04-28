#ifndef TYPE_DIAPORAMA_H
#define TYPE_DIAPORAMA_H
#include <iostream>
using namespace std;
#include <vector>
#include "image.h"
#include "imagedansdiaporama.h"


class Diaporama
{

private :
    string titre ;  // titre du diaporama
    unsigned int vitesseDefilement; // vitesse de défilement des images du diaporama
    vector <ImageDansDiaporama> localisationImages; // images du diaporama


public:
    Diaporama();
    void creerDiaporama (Diaporama* pDiaporama);
};


typedef vector<Image> Images;
typedef vector<Diaporama> Diaporamas;


#endif // TYPE_DIAPORAMA_H
