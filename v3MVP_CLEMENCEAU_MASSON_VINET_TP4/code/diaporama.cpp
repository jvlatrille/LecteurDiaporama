#include "diaporama.h"

Diaporama::Diaporama():id(0), titre(""), vitesseDefilement(0) {
    images.clear();
}

Diaporama::~Diaporama()
{
    vider();
}

unsigned int Diaporama::getId() const
{
    return id;
}

string Diaporama::getTitre() const
{
    return titre;
}

int Diaporama::getVitesseDefilement() const
{
    return vitesseDefilement;
}

ImagesDiaporama Diaporama::getImages() const
{
    return images;
}

unsigned int Diaporama::getPosImageCourante() const
{
    return posImageCourante;
}

ImageDansDiaporama* Diaporama::getImageCourante() const
{
    return getImages()[getPosImageCourante()];
}

unsigned int Diaporama::nbImages() const
{
    return images.size();
}

void Diaporama::setId(unsigned int pId)
{
    id = pId;
}

void Diaporama::setTitre(string pTitre)
{
    titre = pTitre;
}

void Diaporama::setVitesseDefilement(unsigned int pVitesseDefilement)
{
    vitesseDefilement = pVitesseDefilement;
}

void Diaporama::setImages(const ImagesDiaporama& pImages)
{
    images = pImages;
}

void Diaporama::ajouterImageEnFin(ImageDansDiaporama* pImage)
{
    images.push_back(pImage);

    // post-condition : nbImages() > 0
}

void Diaporama::enleverImageEnFin()
{
    if (nbImages() != 0)
    {
        images.pop_back();
    }

    // post-condition : nbImages() >= 0
}

void Diaporama::vider()
{
    unsigned int taille = nbImages();
    for (unsigned int i = 0; i < taille ; i++)
    {
        enleverImageEnFin(); /* Removes the last element in the vector,
                              effectively reducing the container size by one.
                              AND deletes the removed element */
    }
    // post-condition : nbImages() == 0
}

void Diaporama::charger()
{
    /* Chargement des images associées au diaporama id.
       Crée un objet Image pour chaque image de ce diaporama, puis stocke son adresse dans l'attribut images.
       La collection  est ensuite triée par ordre croissant de rang des images.

       Dans la version actuelle, les images sont créées 'en dur'.
       Dans une version ultérieure, les images proviendront de la Base de Données */


    ImageDansDiaporama* imageACharger;
    switch(id) {
    case 0 : // diaporama par défaut
        imageACharger = new ImageDansDiaporama(1, "objet", "", "C:\\cartesDisney\\Disney_tapis.gif");
        ajouterImageEnFin(imageACharger);
        break ;//
    case 1 : // diaporama de Pantxika
        imageACharger = new ImageDansDiaporama(3, "personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(2, "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(4, "personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(1, "animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif");
        ajouterImageEnFin(imageACharger);
        break ;//
    case 2 : // diaporama de Thierry
        imageACharger = new ImageDansDiaporama(1, "personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(2, "personnage", "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(3, "personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(4, "animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif");
        ajouterImageEnFin(imageACharger);
        break ;//
    case 3 : // diaporama de Yann
        imageACharger = new ImageDansDiaporama(2, "personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(1, "personnage", "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(4, "personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(3, "animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif");
        ajouterImageEnFin(imageACharger);
        break ;//
    case 4 : // diaporama de Manu
        imageACharger = new ImageDansDiaporama(4, "personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(3, "personnage", "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(2, "personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(1, "animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif");
        ajouterImageEnFin(imageACharger);
        break ;//
    default : break;
    }

    trierParRangCroissant();  // selon le rang de l'image dans le diaporama

    // post-condition : nbImages() >= 0
}

void Diaporama::trierParRangCroissant()
{
    ImageDansDiaporama* pteurImage;
    unsigned int taille = nbImages();
    for (unsigned int ici = taille-1; ici >=1 ; ici--)
    {
        // faire monter la bulle ici = déplacer l'élément de rang le plus grand en position ici
        // par échanges successifs
        for (unsigned int i = 0; i < ici; i++)
        {
            if (images[i]->getRangDansDiaporama() > images[i+1]->getRangDansDiaporama())
            {
                // echanger les 2 éléments
                pteurImage = images[i];
                images[i] = images[i+1];
                images[i+1] = pteurImage;
            }
        }
    }
}

