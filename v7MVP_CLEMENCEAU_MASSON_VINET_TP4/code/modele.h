#ifndef MODELE_H
#define MODELE_H

#include <QObject>
#include <vector>
#include "diaporama.h"
#include "lecteur.h"
#include "vit.h"
#include <QTimer>
#include "database.h"


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
    Diaporama diaporama;

public:
    Modele();

    enum UnEtat {manuel, automatique, defaut};

    // Getters
    unsigned int getVitesseDefilement() const;
    unsigned int getPosImageCourante() const;
    Diaporama* getDiaporama() const;
    UnEtat getEtat() const;
    Lecteur *  getLecteur() const;

    // Setters
    void setVitesseDefilement(unsigned int);
    void setDiaporama(Diaporama *);
    void setPosImageCourante(unsigned int pPosImageCourante);
    void setEtat(UnEtat e);
    void setLecteur(Lecteur * newLecteur);

    // Méthode pour charger un diaporama
    void chargerDiapo(unsigned int id, const QString &titre, int vitesseDefilement);
    unsigned int nbImages() const;
    int* vitesse;

    // Méthodes pour bouger dans le diaporama
    void avancer();
    void reculer();
    void avanceAuto();
    void avancerAuto();
    void reculerAuto(); // J'crois qu'elle sert à rien celle là

    void changerVitesse(vit*);
    void etatAutomatique();
    void etatManuel();
    void enleverDiapo();

signals:
    void imageChange(const QString &titreDiapo, const QString &titreImage, const QString &categorie, const QString &rang, const QString &chemin); // Signal émis quand l'image change avec toute les infos
    void vitesseChangee(int vitesse); // Signal émis quand la vitesse change

private : // Déclaré après car enum UnEtat dans le public
    UnEtat _etat;

};

#endif // MODELE_H
