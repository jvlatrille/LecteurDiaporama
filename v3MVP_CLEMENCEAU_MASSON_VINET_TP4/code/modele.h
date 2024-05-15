#ifndef MODELE_H
#define MODELE_H

#include <QObject>
#include <vector>
#include <iostream>
#include "diaporama.h"

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
    void triCroissantRang();

public:
    Modele();

    unsigned int getVitesseDefilement() const;
    unsigned int getPosImageCourante() const;
    unsigned int nbImages() const;

    Diaporama* getDiaporama() const;

    void setVitesseDefilement(unsigned int);
    void setDiaporama(Diaporama *);
    void setPosImageCourante(unsigned int pPosImageCourante);

    void avancer();
    void reculer();
    void departArretAuto();
    void changerVitesse();
    void etatAutomatique();
    void etatManuel();
    void chargerDiapo();
    void enleverDiapo();
    void aPropos();


    enum UnEtat {manuel, automatique};
    UnEtat getEtat();

private :
    UnEtat _etat;
};

#endif // MODELE_H
