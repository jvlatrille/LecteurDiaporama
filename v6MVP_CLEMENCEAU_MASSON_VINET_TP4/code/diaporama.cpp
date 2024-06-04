#include "diaporama.h"
#include "database.h"
#include "lecteurvue.h"

Diaporama::Diaporama():id(1), titre(""), vitesseDefilement(0) {
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

/*
    ImageDansDiaporama* imageACharger;
    switch(id) {
    case 0 : // diaporama par défaut
        imageACharger = new ImageDansDiaporama(1, "objet", "", ":/images/cartesDisney/Disney_tapis.gif");
        ajouterImageEnFin(imageACharger);
        break ;//
    case 1 : // diaporama de Pantxika
        imageACharger = new ImageDansDiaporama(3, "personnage", "Pinnochio", ":/images/cartesDisney/Disney_29.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(2, "personnage", "Blanche Neige", ":/images/cartesDisney/Disney_4.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(4, "personnage", "Alice", ":/images/cartesDisney/Disney_2.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(1, "animal", "Mickey", ":/images/cartesDisney/Disney_19.gif");
        ajouterImageEnFin(imageACharger);
        break ;//
    case 2 : // diaporama de Thierry
        imageACharger = new ImageDansDiaporama(1, "personnage", "Timon", ":/images/cartesDisney/Disney_40.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(2, "personnage", "Dragon de jsp", ":/images/cartesDisney/Disney_10.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(3, "personnage", "Bambi <3",":/images/cartesDisney/Disney_3.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(4, "animal", "Pluto", ":/images/cartesDisney/Disney_30.gif");
        ajouterImageEnFin(imageACharger);
        break ;//
    case 3 : // diaporama de Yann
        imageACharger = new ImageDansDiaporama(2, "personnage", "Gepeto", ":/images/cartesDisney/Disney_25.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(1, "personnage", "Cendrillon", ":/images/cartesDisney/Disney_49.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(4, "personnage", "Donald",":/images/cartesDisney/Disney_8.gif"); //
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(3, "animal", "Donald mais pas content", ":/images/cartesDisney/Disney_9.gif");
        ajouterImageEnFin(imageACharger);
        break ;//
    case 4 : // diaporama de Manu
        imageACharger = new ImageDansDiaporama(4, "personnage", "Simba", ":/images/cartesDisney/Disney_33.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(3, "personnage", "101 dalmassiens", ":/images/cartesDisney/Disney_1.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(2, "personnage", "Stitch", ":/images/cartesDisney/Disney_37.gif");
        ajouterImageEnFin(imageACharger);
        imageACharger = new ImageDansDiaporama(1, "animal", "La belle et le clochard", ":/images/cartesDisney/Disney_6.gif");
        ajouterImageEnFin(imageACharger);
        break ;//
    default : break;
    }

    trierParRangCroissant();  // selon le rang de l'image dans le diaporama
    // post-condition : nbImages() >= 0*/

    QSqlQuery query;
    QString requete;
    requete = "SELECT F.nomFamille,DI.uriPhoto, DI.titrePhoto, DDD.rang, D.idDiaporama FROM Diapos DI JOIN Familles F ON F.idFamille = DI.idFam JOIN DiaposDansDiaporama DDD ON DDD.idDiapo = DI.idphoto JOIN Diaporamas D ON D.idDiaporama = DDD.idDiaporama ORDER BY DDD.idDiapo;";
    query.prepare(requete);
    query.bindValue(":idDiaporama", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :";
    }
    while (query.next()) {
        ImageDansDiaporama* imageACharger;
        switch(id) {
        case 1 : // diaporama de Pantxikaka
            while (query.next()){
                int rang =query.value(3).toInt();
                string categorie = query.value(1).toString().toStdString();
                string nomPersonnages = query.value(2).toString().toStdString();
                string path = query.value(0).toString().toStdString();
                imageACharger = new ImageDansDiaporama(rang, categorie, nomPersonnages, path);
                ajouterImageEnFin(imageACharger);
            }
            break ;//
        case 2 : // diaporama de Thierry
            while (query.next()){
                int rang =query.value(3).toInt();
                string categorie = query.value(1).toString().toStdString();
                string nomPersonnages = query.value(2).toString().toStdString();
                string path = query.value(0).toString().toStdString();
                imageACharger = new ImageDansDiaporama(rang, categorie, nomPersonnages, path);
                ajouterImageEnFin(imageACharger);
            }
            break ;//
        case 3 : // diaporama de Yann
            while (query.next()){
                int rang =query.value(3).toInt();
                string categorie = query.value(1).toString().toStdString();
                string nomPersonnages = query.value(2).toString().toStdString();
                string path = query.value(0).toString().toStdString();
                imageACharger = new ImageDansDiaporama(rang, categorie, nomPersonnages, path);
                ajouterImageEnFin(imageACharger);
            }
            break ;//
        case 4 : // diaporama de Manu
            while (query.next()){
                int rang =query.value(3).toInt();
                string categorie = query.value(1).toString().toStdString();
                string nomPersonnages = query.value(2).toString().toStdString();
                string path = query.value(0).toString().toStdString();
                imageACharger = new ImageDansDiaporama(rang, categorie, nomPersonnages, path);
                ajouterImageEnFin(imageACharger);
            }
            break ;//
        default : break;
        }
    }
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

