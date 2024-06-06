#include "modele.h"
#include "ui_vit.h"
#include "vit.h"
#include <QDialog>



Modele::Modele()
{

}

unsigned int Modele::getVitesseDefilement(unsigned int diapoActuel)
{
    qDebug() << "zzzzzzzzzzzzzzzzzzzzzzzzzzzz on à la vitesse";
    unsigned int vitesseDefilement = 1000; // Valeur par défaut
    database db;
    if (!db.ouvrirBD()) {
        qDebug() << "BD non ouverte";
        db.ouvrirBD();
    }

    QSqlQuery query(db.getDatabase());
    QString requete = QString("SELECT vitesseDefilement FROM Diaporamas WHERE idDiaporama = :diapoActuel");
    query.prepare(requete);
    query.bindValue(":diapoActuel", diapoActuel);

    if (query.exec()) {
        if (query.next()) {
            vitesseDefilement = query.value(0).toUInt();
        }
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
    }

    db.fermerBD();
    return vitesseDefilement * 1000;
}



bool Modele::lecteurVide() const
{
    return (getDiaporama() == nullptr);
}

Lecteur* Modele::getLecteur() const
{
    return lecteur;
}

void Modele::setLecteur(Lecteur* newLecteur)
{
    lecteur = newLecteur;
}


unsigned int Modele::getPosImageCourante() const
{
    return m_posImageCourante;
}

unsigned int Modele::nbImages() const
{
    if (lecteurVide())
    {
        throw string ("lecteur vide");
    }
    return m_MonDiapo->nbImages();
}


Diaporama *Modele::getDiaporama() const
{
    return m_MonDiapo;
}


void Modele::setVitesseDefilement(unsigned int vitesse)
{
    m_vitesseDefilement = vitesse;
}

void Modele::changerVitesse(vit* fenetreV) {
    int nouvelleVitesse = fenetreV->ui->sVit->value();
    setVitesseDefilement(nouvelleVitesse);
    emit vitesseChangee(nouvelleVitesse);
    qDebug() << "La nouvelle vitesse est :" << nouvelleVitesse;

}


void Modele::setPosImageCourante(unsigned int pPosImageCourante)
{
    m_posImageCourante = pPosImageCourante;
}


void Modele::setDiaporama(Diaporama *diaporama)
{
        m_MonDiapo = diaporama;
}

Modele::UnEtat Modele::getEtat() const {
    return _etat;
}

void Modele::setEtat(UnEtat e)
{
    _etat = e;
}

void Modele::avancer() {
        qDebug() << "Modele::avance";

        lecteur->avancer();
        qDebug() << "le lecteur à avancé";

        if (!lecteur->getDiaporama()) {
            qDebug() << "Diaporama est nul";
            return;
        }

        ImageDansDiaporama* imageCourante = lecteur->getImageCourante();
        if (!imageCourante) {
            qDebug() << "Aucune image courante";
            return;
        }

        qDebug() << "Image courante créée";
        emit imageChange(QString::fromStdString(lecteur->getDiaporama()->getTitre()),
                         QString::fromStdString(imageCourante->getTitre()),
                         QString::fromStdString(imageCourante->getCategorie()),
                         QString::number(imageCourante->getRangDansDiaporama()),
                         QString::fromStdString(imageCourante->getChemin()));

}


void Modele::reculer()
{

        qDebug() << "Modele::recule";
        lecteur->reculer();
        qDebug() << "le lecteur à reculé";

        if (!lecteur->getDiaporama()) {
            qDebug() << "Diaporama est nul";
            return;
        }

        ImageDansDiaporama* imageCourante = lecteur->getImageCourante();
        if (!imageCourante) {
            qDebug() << "Aucune image courante";
            return;
        }

        qDebug() << "Image courante créée";
        emit imageChange(QString::fromStdString(lecteur->getDiaporama()->getTitre()),
                         QString::fromStdString(imageCourante->getTitre()),
                         QString::fromStdString(imageCourante->getCategorie()),
                         QString::number(imageCourante->getRangDansDiaporama()),
                         QString::fromStdString(imageCourante->getChemin()));

        qDebug() << "Signaux à jour envoyés";

        if(_etat == automatique)
        {
            etatManuel();
        }


}

void Modele::avanceAuto() {
    if (_etat != automatique) {
        qDebug() << "Tentative d'avance automatique alors que le mode n'est pas automatique.";
        return;  // Assure que l'avance automatique ne fonctionne que si l'état est correct.
    }

    if (lecteur && lecteur->getDiaporama()) {
        lecteur->avancer();  // Avance à l'image suivante dans le diaporama.

        ImageDansDiaporama* imageCourante = lecteur->getImageCourante();
        if (imageCourante) {
            emit imageChange(
                QString::fromStdString(lecteur->getDiaporama()->getTitre()),
                QString::fromStdString(imageCourante->getTitre()),
                QString::fromStdString(imageCourante->getCategorie()),
                QString::number(imageCourante->getRangDansDiaporama()),
                QString::fromStdString(imageCourante->getChemin())
            );
        } else {
            qDebug() << "Aucune image courante disponible après avance.";
        }
    } else {
        qDebug() << "Lecteur ou diaporama nul, avance automatique non possible.";
    }
}



void Modele::etatAutomatique()
{
    setEtat(automatique);
    while(_etat == automatique){
        avanceAuto();
    }


}

void Modele::etatManuel()
{
    _etat = UnEtat::manuel;
    qDebug() << "Mode manuel";
}


void Modele::triCroissantRang()
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

void Modele::chargerDiapo(unsigned int id, const QString &titre, int vitesseDefilement) {
    // Changer le diaporama
    lecteur->changerDiaporama(id, titre.toStdString(), vitesseDefilement);

    // Rechargez l'image courante après avoir changé le diaporama
    ImageDansDiaporama* imageCourante = lecteur->getImageCourante();
    if (imageCourante == nullptr) {
        qDebug() << "imageCourante est nul après changement de diaporama";
        return;
    }
    qDebug() << "Titre diaporama:" << titre;
    qDebug() << "Titre image:" << QString::fromStdString(imageCourante->getTitre());
    qDebug() << "Catégorie image:" << QString::fromStdString(imageCourante->getCategorie());
    qDebug() << "Rang dans diaporama:" << QString::number(imageCourante->getRangDansDiaporama());
    qDebug() << "Chemin image:" << QString::fromStdString(imageCourante->getChemin());

    emit imageChange(
        titre,
        QString::fromStdString(imageCourante->getTitre()),
        QString::fromStdString(imageCourante->getCategorie()),
        QString::number(imageCourante->getRangDansDiaporama()),
        QString::fromStdString(imageCourante->getChemin())
    );

    qDebug() << "Etape 3";
    setEtat(manuel);
}




void Modele::enleverDiapo() {
    _etat = UnEtat::defaut;
    qDebug() << "Diapo retiré";
}
