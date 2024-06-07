#ifndef MODELE_H
#define MODELE_H

#include <QObject>
#include <vector>
#include "diaporama.h"
#include "lecteur.h"
#include "vit.h"
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
    // But : Vérifie que le lecteur est vide ou non

    unsigned int m_posImageCourante;
    vector <ImageDansDiaporama> m_localisationImages;
    Diaporama* m_MonDiapo;
    ImagesDiaporama images;
    Lecteur * lecteur;
    void triCroissantRang();
    // But : Tri des images

public:
    Modele();

    enum UnEtat {manuel, automatique, defaut};

    // Getters
    unsigned int getVitesseDefilement() const;
    unsigned int getPosImageCourante() const;
    unsigned int nbImages() const;

    int* vitesse; // Vitesse de défilement

    // getters
    UnEtat getEtat() const;
    Diaporama* getDiaporama() const;
    Lecteur *  getLecteur() const;

    // Setters
    void setEtat(UnEtat e);
    void setVitesseDefilement(unsigned int);
    void setDiaporama(Diaporama *);
    void setPosImageCourante(unsigned int pPosImageCourante);
    void setLecteur(Lecteur * newLecteur);


    void avancer();
    void reculer();
    void avanceAuto();
    void chargerDiapo(unsigned int id, const QString &titre, int vitesseDefilement);
    void changerVitesse(vit*);
    void etatAutomatique();
    void etatManuel();
    void enleverDiapo();



signals:
    void imageChange(const QString &titreDiapo, const QString &titreImage, const QString &categorie, const QString &rang, const QString &chemin);
    void vitesseChangee(int vitesse);

private :
    UnEtat _etat;
};

#endif // MODELE_H
