#include <iostream>
#include <vector>
#include "diaporama.h"
#include "lecteur.h"
using namespace std;



int main()
{
    /* -------------------------------------------------------------------------------------
     * Charge les images et les diaporamas 'en dur' ... en attendant l'implantation de la BD :
     * - Charger les images et diaporamas
     * Dans un second temps, ces contenus proviendront d'une base de données
     --------------------------------------------------------------------------------------*/
    Lecteur lecteurDiapos;
    vector<Image> images;          // les images

    // Chargement des urls des images, chargement des diaporamas
    lecteurDiapos.chargerImages(images);
    lecteurDiapos.chargerDiapos(images);


    //lecteurDiapos.getDiapoCourant().afficherImageCouranteDansDiaporamaCourant();
    cout << "Nombre de diapos : " << lecteurDiapos.getNombreDiapos() << endl;

    // Trier les diapos en fonction du rang des images dans celles-ci
    for(unsigned int i = 1; i < lecteurDiapos.getNombreDiapos(); i++)
    {
        cout << "Tri numéro " << i << endl;
        lecteurDiapos.getAllDiapos()[i].triCroissantRang();
    }


    /* ---------------------
     * Lecteur de diaporamas
     * --------------------- */


    /* Faire fonctionner le lecteur
       --------------*/
    char choixAction;              // pour saisir le choix de l'utilisateur dans le menu d'actions possibles
    while (true)
    {

        /* Affichage à l'écran des infos de l'image courante dans son diaporama   */
        system("cls");  // effacer l'écran

        //unsigned int position = diaporamas[diaporamaCourant].getLocalisationImages()[imageCourante].getPos();
        lecteurDiapos.getDiapoCourant().afficherImageCouranteDansDiaporamaCourant();

        /* Menu des actions possibles (saisie choix utilisateur) :
         * A-vancer, R-eculer, C-hanger de diaporama, Q-uitter */

        lecteurDiapos.saisieChoixActionImageCourante(choixAction);

        if (choixAction == 'Q')
        {
            break;
        }

        /* Faire l'action demandée (Avancer - Reculer - Changer de Diaporama - Quitter) */
        system("cls");  // effacer l'écran
    }

    /* Fin
       --------------*/
    cout << "Au revoir " << endl;
    return 0;
}

