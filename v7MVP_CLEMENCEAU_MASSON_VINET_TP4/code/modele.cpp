#include "modele.h"
#include "ui_vit.h"
#include "vit.h"
#include <QDialog>



Modele::Modele()
{

}

unsigned int Modele::getVitesseDefilement() const
{
    return m_vitesseDefilement;
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
    int nouvelleVitesse = fenetreV->ui->sVit->value(); // Récupère la nouvelle vitesse depuis l'interface utilisateur
    setVitesseDefilement(nouvelleVitesse);
    emit vitesseChangee(nouvelleVitesse); // Émet un signal pour indiquer que la vitesse a changé
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
    qDebug() << "Modele::avance"; // Log pour indiquer que la méthode avancer est appelée
    lecteur->avancer(); // Appeler la méthode avancer du lecteur
    qDebug() << "le lecteur a avancé"; // Log pour confirmer que le lecteur a avancé

    // Vérifier si le diaporama est valide
    if (!lecteur->getDiaporama()) {
        qDebug() << "Diaporama est nul"; // Log pour indiquer que le diaporama est nul
        return; // Sortir de la méthode
    }

    // Récupérer l'image courante du lecteur
    ImageDansDiaporama* imageCourante = lecteur->getImageCourante();
    if (!imageCourante) {
        qDebug() << "Aucune image courante"; // Log pour indiquer qu'il n'y a pas d'image courante
        return; // Sortir de la méthode
    }

    qDebug() << "Image courante créée"; // Log pour indiquer que l'image courante est récupérée avec succès
    // Émettre un signal avec les informations de l'image courante
    emit imageChange(QString::fromStdString(lecteur->getDiaporama()->getTitre()),
                     QString::fromStdString(imageCourante->getTitre()),
                     QString::fromStdString(imageCourante->getCategorie()),
                     QString::number(imageCourante->getRangDansDiaporama()),
                     QString::fromStdString(imageCourante->getChemin()));
}


void Modele::reculer()
{
    qDebug() << "Modele::recule"; // Log pour indiquer que la méthode reculer est appelée
    lecteur->reculer(); // Appeler la méthode reculer du lecteur
    qDebug() << "le lecteur a reculé"; // Log pour confirmer que le lecteur a reculé

    // Vérifier si le diaporama est valide
    if (!lecteur->getDiaporama()) {
        qDebug() << "Diaporama est nul"; // Log pour indiquer que le diaporama est nul
        return; // Sortir de la méthode
    }

    // Récupérer l'image courante du lecteur
    ImageDansDiaporama* imageCourante = lecteur->getImageCourante();
    if (!imageCourante) {
        qDebug() << "Aucune image courante"; // Log pour indiquer qu'il n'y a pas d'image courante
        return; // Sortir de la méthode
    }

    qDebug() << "Image courante créée"; // Log pour indiquer que l'image courante est récupérée avec succès
    // Émettre un signal avec les informations de l'image courante
    emit imageChange(QString::fromStdString(lecteur->getDiaporama()->getTitre()),
                     QString::fromStdString(imageCourante->getTitre()),
                     QString::fromStdString(imageCourante->getCategorie()),
                     QString::number(imageCourante->getRangDansDiaporama()),
                     QString::fromStdString(imageCourante->getChemin()));

    qDebug() << "Signaux à jour envoyés"; // Log pour confirmer que les signaux ont été envoyés

    // Passer en mode manuel si on était en mode automatique
    if(_etat == automatique)
    {
        etatManuel();
    }
}

void Modele::avanceAuto() {
    // Vérifier si l'état est bien automatique
    if (_etat != automatique) {
        qDebug() << "Tentative d'avance automatique alors que le mode n'est pas automatique.";
        return;  // Sortir de la méthode si l'état n'est pas automatique
    }

    // Vérifier que le lecteur et le diaporama sont valides
    if (lecteur && lecteur->getDiaporama()) {
        lecteur->avancer();  // Avancer à l'image suivante dans le diaporama

        // Récupérer l'image courante après l'avance
        ImageDansDiaporama* imageCourante = lecteur->getImageCourante();
        if (imageCourante) {
            // Émettre un signal avec les informations de l'image courante
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
    lecteur->changerDiaporama(id, titre.toStdString(), vitesseDefilement); // Changer le diaporama

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

    // Émettre un signal avec les informations de l'image courante
    emit imageChange(
        titre,
        QString::fromStdString(imageCourante->getTitre()),
        QString::fromStdString(imageCourante->getCategorie()),
        QString::number(imageCourante->getRangDansDiaporama()),
        QString::fromStdString(imageCourante->getChemin())
        );

    qDebug() << "Etape 3";
    setEtat(manuel); // Passer en mode manuel après avoir chargé le diaporama
}

void Modele::enleverDiapo() {
    _etat = UnEtat::defaut;
    qDebug() << "Diapo retiré";
}
