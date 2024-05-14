#ifndef LECTEUR_H
#define LECTEUR_H
#include "imageDansDiaporama.h"
#include "diaporama.h"
#include <vector>
#include <QObject>

/* Caractéristiques du lecteur :
 * - au lancement de l'application, le lecteur est vide  = aucun diaporama n'est associé au lecteur.
     Il faut donc commencer par le charger avant de pouvoir afficher une image.
   - en contrepartie, il est aussi désormais possible de 'vider' le lecteur, c'est à dire de dissocier un éventuel
     diaporama qui lui aurait été associé.
*/

class Lecteur : public QObject
{
public:
    Lecteur();
    ~Lecteur();

    unsigned int getIdDiaporama() const;
    Diaporama* getDiaporama() const;
    unsigned int getPosImageCourante() const;
    bool lecteurVide() const;                         // = vrai si aucun diaporama ssocié au lecteur, faux Sinon
    ImageDansDiaporama* getImageCourante() const;     // retourne le pointeur vers l'image courante
    unsigned int nbImages() const;                    // taille de la collection pointée par diaporama

    void afficher();            // affiche les informations sur lecteur + éventuellement diaporama et image courante

    void setIdDiaporama(unsigned int pIdDiaporama);
    void setDiaporama (Diaporama* pDiaporama);
    void setPosImageCourante(unsigned int pPosImageCourante);

    void changerDiaporama(unsigned int pId, string pTitre="", unsigned int pVitesse=0);

    void viderLecteur();

private:
    unsigned idDiaporama;
    Diaporama* diaporama;
    unsigned int posImageCourante;

    void chargerDiaporamaCourant();


public slots:
    void avancer();
    void reculer();
    void departArretAuto();
    void changerVitesse();
    void changerModeAutomatique();
    void changerModeManuel();
    void chargerDiapo();    //
    void quitter();
    void enleverDiapo();
    void ouvrirAPropos();



};

#endif // LECTEUR_H
