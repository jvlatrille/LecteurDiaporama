#ifndef MODELE_H
#define MODELE_H
#include "qDebug"
#include <QObject>
#include <vector>
#include <imageDansDiaporama.h>
#include <diaporama.h>
#include <iostream>
using namespace std;

class Modele : public QObject
{
    Q_OBJECT
private:
    string m_titre;
    unsigned int m_vitesseDefilement;
    unsigned int m_posImageCourante;
    vector <imageDansDiaporama> m_localisationImages;
public:
    explicit Modele(/*UnEtat e=eteint*/ QObject *parent = nullptr);
    string getTitre();

    //void allumer();
    // modifie etat à valeur: allumer
    //void eteindre();
    // modifie etat à valeur :eteindre
    //UnEtat getEtat();
    // getter : retourne valeur de etat

};

#endif // MODELE_H
