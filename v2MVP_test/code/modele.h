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
    std::string m_titre;
    unsigned int m_vitesseDefilement;
    unsigned int m_posImageCourante;
    std::vector<ImageDansDiaporama> m_localisationImages;
    unsigned int m_posImage;

public:
    Modele();

    unsigned int getVitesseDefilement() const;
    unsigned int getPosImageCourante() const;
    Diaporama * getDiaporama() const;

    void setVitesseDefilement(unsigned int);
    void setDiaporama(Diaporama *);

    void avancer();
    void reculer();
    void triCroissantRang();
};

#endif // MODELE_H
