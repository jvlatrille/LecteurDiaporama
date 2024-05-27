#include "modele.h"
#include <QDialog>
#include "ui_apropos.h"
#include "ui_vit.h"


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
        avancerAuto();
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


void Modele::changerVitesse() {
    QDialog* vitDialog = new QDialog();
    Ui::vit vitUi;
    vitUi.setupUi(vitDialog);
    vitDialog->exec();
    delete vitDialog;
}

void Modele::chargerDiapo() {
    // Implémentation du chargement de diaporama
}

void Modele::enleverDiapo() {
    // Implémentation de l'enlèvement de diaporama
}

void Modele::aPropos() {
    QDialog* aproposDialog = new QDialog();
    Ui::apropos aproposUi;
    aproposUi.setupUi(aproposDialog);
    aproposDialog->exec();
    delete aproposDialog;
}


void Modele::avancerAuto()
{
    lecteur->reculer();
    if (!lecteur->getDiaporama()) {
        return;
    }
    ImageDansDiaporama* imageCourante = lecteur->getImageCourante();
    if (!imageCourante) {
        return;
    }
    emit imageChange(QString::fromStdString(lecteur->getDiaporama()->getTitre()),
                     QString::fromStdString(imageCourante->getTitre()),
                     QString::fromStdString(imageCourante->getCategorie()),
                     QString::number(imageCourante->getRangDansDiaporama()),
                     QString::fromStdString(imageCourante->getChemin()));
}

void Modele::reculerAuto()
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
}

