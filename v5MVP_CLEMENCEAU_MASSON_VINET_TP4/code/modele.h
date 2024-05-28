#ifndef MODELE_H
#define MODELE_H

#include <QObject>
#include <vector>
#include "diaporama.h"
#include "lecteur.h"
#include <QTimer>

class ImageDansDiaporama;
typedef std::vector<ImageDansDiaporama*> ImagesDiaporama;
class Modele : public QObject
{
    Q_OBJECT

private:
    string m_titre;
    unsigned int m_vitesseDefilement = 1000;
    bool lecteurVide() const;
    unsigned int m_posImageCourante;
    vector <ImageDansDiaporama> m_localisationImages;
    Diaporama* m_MonDiapo;
    ImagesDiaporama images;
    Lecteur * lecteur;
    void triCroissantRang();
    QTimer* timer;

public:
    Modele();

    enum UnEtat {manuel, automatique};

    unsigned int getVitesseDefilement() const;
    unsigned int getPosImageCourante() const;
    unsigned int nbImages() const;
    int* vitesse;

    UnEtat getEtat() const;
    void setEtat(UnEtat e);
    Diaporama* getDiaporama() const;

    void setVitesseDefilement(unsigned int);
    void setDiaporama(Diaporama *);
    void setPosImageCourante(unsigned int pPosImageCourante);

    void avancer();
    void reculer();
    void avanceAuto();

    void changerVitesse();
    void etatAutomatique();
    void etatManuel();
    void chargerDiapo();
    void enleverDiapo();
    void aPropos();
    Lecteur *  getLecteur() const;
    void setLecteur(Lecteur * newLecteur);


    void avancerAuto();
    void reculerAuto();


signals:
    void imageChange(const QString &titreDiapo, const QString &titreImage, const QString &categorie, const QString &rang, const QString &chemin);
    void vitesseChangee(int vitesse);

private :
    UnEtat _etat;
};

#endif // MODELE_H
