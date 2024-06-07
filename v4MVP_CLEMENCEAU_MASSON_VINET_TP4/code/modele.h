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
    unsigned int m_vitesseDefilement;
    bool lecteurVide() const;
    unsigned int m_posImageCourante;
    vector <ImageDansDiaporama> m_localisationImages;
    Diaporama* m_MonDiapo;
    ImagesDiaporama images;
    Lecteur * lecteur;
    void triCroissantRang();


public:
    Modele(); // Constructeur

    enum UnEtat {manuel, automatique};

    // Getters
    unsigned int getVitesseDefilement() const;
    unsigned int getPosImageCourante() const;
    unsigned int nbImages() const;
    UnEtat getEtat() const;
    Diaporama* getDiaporama() const;
    Lecteur *  getLecteur() const;

    // Setters

    void setEtat(UnEtat e);
    void setVitesseDefilement(unsigned int);
    void setDiaporama(Diaporama *);
    void setPosImageCourante(unsigned int pPosImageCourante);
    void setLecteur(Lecteur * newLecteur);

    // Autres méthodes
    void avancer();
    void reculer();
    void avanceAuto();
    void changerVitesse();
    void etatAutomatique();
    void etatManuel();
    void chargerDiapo();
    void enleverDiapo();
    void aPropos();





signals:
    void imageChange(const QString &titreDiapo, const QString &titreImage, const QString &categorie, const QString &rang, const QString &chemin);

private :
    UnEtat _etat;
};

#endif // MODELE_H
