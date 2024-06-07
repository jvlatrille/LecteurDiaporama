#ifndef LECTEUR_H
#define LECTEUR_H
#include "imageDansDiaporama.h"
#include "diaporama.h"
#include <vector>

/* Caractéristiques du lecteur :
 * - au lancement de l'application, le lecteur est vide  = aucun diaporama n'est associé au lecteur.
     Il faut donc commencer par le charger avant de pouvoir afficher une image.
   - en contrepartie, il est aussi désormais possible de 'vider' le lecteur, c'est à dire de dissocier un éventuel
     diaporama qui lui aurait été associé.
*/

class Lecteur
{
public:
    Lecteur(); // Constructeur
    ~Lecteur(); // Destructeur

    // Getters
    unsigned int getIdDiaporama() const;
    Diaporama* getDiaporama() const;
    unsigned int getPosImageCourante() const;

    bool lecteurVide() const;                         // = vrai si aucun diaporama ssocié au lecteur, faux Sinon
    ImageDansDiaporama* getImageCourante() const;     // retourne le pointeur vers l'image courante
    unsigned int nbImages() const;                    // taille de la collection pointée par diaporama

    void afficher();            // affiche les informations sur lecteur + éventuellement diaporama et image courante

    // Setters
    void setIdDiaporama(unsigned int pIdDiaporama);
    void setDiaporama (Diaporama* pDiaporama);
    void setPosImageCourante(unsigned int pPosImageCourante);

    void changerDiaporama(unsigned int pId, string pTitre="", unsigned int pVitesse=0);
    /* Permet de choisir un diaporama, 0 si aucun souhaité.
         * 2 formes d'appels :
         * - 1 appel signifiant la demande de chargement d'1 diaporama : utiliser les 3 paramètres, avec pId !=0
         * - 1 appel signifiant la demande de 'vidage' du lecteur : utiliser un seul paramètre : changerDiaporama(0);
          Sera remplacée par la méthode :
               void changerDiaporama(unsigned int pId);
          lorsque les données du diaporama d'identifiant pId proviendront de la Base de données */
    void avancer();
    /* si 1 diaporama non vide est associé au lecteur : incrémente posImageCourante, modulo nbImages()
         * sinon : ne fait rien */
    void reculer();
    /* si 1 diaporama non vide est associé au lecteur : décrémente posImageCourante, modulo nbImages()
         * sinon : ne fait rien */
    void viderLecteur();        // s'il en existe un, enlève le diaporama courant du lecteur

private:
    unsigned idDiaporama;             /* identifiant en Base de Données du diaporama courant,
                                         = 0 si pas de diaporama dans le lecteur */
    Diaporama* diaporama;             /* pointeur vers le diaporama associé au lecteur,
                                         = nullptr si pas de diaporama dans le lecteur) */
    unsigned int posImageCourante;    /* position de l'image courante du diaporama courant.
                                         Indéfinie quand lecteur vide ou diaporama vide.
                                         >= 0 quand lecteur non vide et diaporama non vide */
private:
    void chargerDiaporamaCourant();    // charge dans le lecteur ImageDansDiaporama du numDiaporamaCourant
};

#endif // LECTEUR_H
