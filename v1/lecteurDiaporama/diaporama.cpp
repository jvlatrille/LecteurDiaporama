#include "diaporama.h"



// Les constructeurs
Diaporama::Diaporama() :
    _titre(""),
    _vitesseDefilement(0),
    _localisationImages({}),
    _posImageCourante(0)
    {}

Diaporama::Diaporama(string titre, unsigned int vitesseDefilement, ImagesDuDiaporama _localisationImages, unsigned int posImgCourante) :
    _titre(titre),
    _vitesseDefilement(vitesseDefilement),
    _localisationImages(_localisationImages),
    _posImageCourante(posImgCourante)
    {}



// Les getters

string Diaporama::getTitre() const
{
    return _titre;
}

ImagesDuDiaporama Diaporama::getLocalisationImages() const
{
    return _localisationImages;
}

unsigned int Diaporama::getVitesseDefilement() const
{
    return _vitesseDefilement;
}

unsigned int Diaporama::getNombreImages() const
{
    return _localisationImages.size();
}

unsigned int Diaporama::getPosImageCourante() const
{
    return _posImageCourante;
}

imageDansDiaporama Diaporama::getImageCourante() const
{
    return getLocalisationImages()[getPosImageCourante()];
}



// Les setters

void Diaporama::setTitre(const string& titre)
{
    _titre = titre;
}

void Diaporama::setVitesseDefilement(unsigned int vitesseDefilement)
{
    _vitesseDefilement = vitesseDefilement;
}

void Diaporama::setLocalisationImages(const ImagesDuDiaporama& localisationImages)
{
    _localisationImages = localisationImages;
}

void Diaporama::setPosImageCourante(unsigned int pPosCourante)
{
    _posImageCourante = pPosCourante;
}



// Sous-programmes

void Diaporama::ajouterImage(const imageDansDiaporama& imgDuDiapo)
{
    _localisationImages.push_back(imgDuDiapo);
}

void Diaporama::avancer()
{
    // Vérifier la postion actuelle (si c'est la dernière image du diaporama, on passe à l'indice 0 (la première))
    if (getPosImageCourante() == getNombreImages() - 1)
    {
        setPosImageCourante(0);
    }
    else {
        setPosImageCourante(getPosImageCourante() + 1);
    }
}


void Diaporama::reculer()
{
    // Vérifier la postion actuelle (si c'est la première image du diaporama, on passe à l'indice -1 ( la dernière))
    if (getPosImageCourante() == 0)
    {
       setPosImageCourante(getNombreImages() - 1);
    }
    else
    {
        setPosImageCourante(getPosImageCourante() - 1);
    }
}

void Diaporama::afficherImageCouranteDansDiaporamaCourant () const
{
    cout << endl << endl;
    cout << "DIAPORAMA : " << getTitre();
    cout << endl << endl;
    cout << getImageCourante().getRang() << " sur " << getNombreImages() << " / ";
    cout << endl << endl;
    getImageCourante().afficherImageCourante();
}

// Tri à bulles
void Diaporama::triCroissantRang() {
    unsigned int taille = _localisationImages.size();

    // Parcourir le tableau jusqu'à ce qu'il n'y ait plus d'échanges à effectuer
    for (unsigned int i = 0; i < taille - 1; i++) {
        bool estEchange = false;

        // Parcourir le tableau à partir de la première image
        for (unsigned int j = 0; j < taille - i - 1; j++) {
            // Comparer le rang de l'image actuelle avec celui de l'image suivante
            if (this->_localisationImages[j].getRang() > this->_localisationImages[j + 1].getRang()) {
                // Échanger les deux images si elles ne sont pas dans le bon ordre
                swap(this->_localisationImages[j], this->_localisationImages[j + 1]);
                estEchange = true; // Indiquer qu'un échange a été effectué
            }
        }
        // Si aucun échange n'a été effectué pendant cette itération, le tableau est déjà trié
        if (!estEchange) {
            break;
        }
    }
}


