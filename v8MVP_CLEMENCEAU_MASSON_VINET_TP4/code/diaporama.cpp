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
    maBD.ouvrirBD();
    QSqlQuery query;
    QString requete = QString("SELECT F.nomFamille, DI.uriPhoto, DI.titrePhoto, DDD.rang, D.idDiaporama "
                              "FROM Diapos DI "
                              "JOIN Familles F ON F.idFamille = DI.idFam "
                              "JOIN DiaposDansDiaporama DDD ON DDD.idDiapo = DI.idphoto "
                              "JOIN Diaporamas D ON D.idDiaporama = DDD.idDiaporama "
                              "WHERE D.idDiaporama = %1 "
                              "ORDER BY DDD.rang;").arg(id);
    query.prepare(requete);

    if(query.exec()){
        while (query.next()) {
            int rang = query.value(3).toInt();
            string categorie = query.value(0).toString().toStdString();
            string nomPersonnages = query.value(2).toString().toStdString();
            string path = ":/images/" + query.value(1).toString().toStdString();
            ImageDansDiaporama* imageACharger = new ImageDansDiaporama(rang, categorie, nomPersonnages, path);
            ajouterImageEnFin(imageACharger);
        }
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête" << query.lastError().text();
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

