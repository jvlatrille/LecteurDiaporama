#include "lecteur.h"
#include "diaporama.h"
#include "image.h"
#include <limits>



// Les constructeurs
Lecteur::Lecteur():
    _numDiapoCourant(0)
{}

Lecteur::Lecteur(Diaporamas diapos, unsigned int numDiapoCourant) :
    _touteDiapos(diapos),
    _numDiapoCourant(numDiapoCourant)
{}


// Les getters
Diaporamas Lecteur::getToutesDiapos() const
{
    return _touteDiapos;
}

Diaporama& Lecteur::getDiapoCourant()
{
    return _touteDiapos[getNumDiapoCourant()];
}

unsigned int Lecteur::getNumDiapoCourant() const
{
    return _numDiapoCourant;
}

unsigned int Lecteur::getNombreDiapos() const
{
    return _touteDiapos.size();
}


// Les setters
void Lecteur::setAllDiapos(const Diaporamas& vecteurDiapos)
{
    _touteDiapos = vecteurDiapos;
}

void Lecteur::setNumDiapoCourant(unsigned int numDiapoCourant)
{
    _numDiapoCourant = numDiapoCourant;
}




// Sous programmes

void Lecteur::afficherDiapoCourant() {
    cout << "Diaporama courant :\n";
    cout << "Titre : " << getDiapoCourant().getTitre() << endl;
    cout << "Vitesse de défilement : " << getDiapoCourant().getVitesseDefilement() << endl;
    cout << "Contenant " << getDiapoCourant().getNombreImages() << " images ";
}

void Lecteur::declencherAction(char pChoixAction)
{
    unsigned int choixDiaporama;
    switch (pChoixAction)
    {
    case 'A':
        // L'utilisateur demande à avancer dans le diaporama
        getDiapoCourant().avancer();
        break;
    case 'R':
        // L'utilisateur demande à reculer dans le diaporama
        getDiapoCourant().reculer();
        break;
    case 'C':
        // L'utilisateur demande à changer de diaporama
        cout << "Choisissez un Diaporama " << endl;
        choixDiaporama = saisieChoixDiaporama();
        setNumDiapoCourant(choixDiaporama);
        getDiapoCourant().setPosImageCourante(0);
        break;
    default:
        break;
    }
}

void Lecteur::saisieChoixActionImageCourante(char& pChoixAction)
{

    cout << endl << endl;
    while (true)
    {
        // Afficher le message et proposer la saisie
        cout << endl << endl;
        cout << "ACTIONS : A-vancer  R-eculer  C-hanger de diaporama  Q-uitter .......  votre choix ? ";
        cin >> pChoixAction;
        pChoixAction = toupper(pChoixAction);

        // Vérifier la saisie
        if ((pChoixAction == 'A') || (pChoixAction == 'R') || (pChoixAction == 'C') || (pChoixAction == 'Q'))
        {
            declencherAction(pChoixAction);
            break;
        }
        else
        {
            cout << "Action non reconnue. Veuillez saisir une action valide." << endl;
        }
    }
}

unsigned int Lecteur::saisieChoixDiaporama()
{
    int choixDiaporama;

    while (true)
    {
        system("cls");

        // Afficher les différents diaporamas
        cout << endl << endl << "CHANGEMENT DIAPORAMA : " << endl << endl;
        for (unsigned int num = 0; num < this->getNombreDiapos(); num++)
        {
            cout << num << ": " << this->getToutesDiapos()[num].getTitre();
            if(num != getNombreDiapos()-1)
            {
                cout << endl; // Faire un retour à la ligne, sauf pour le dernier diapo
            }
        }

        // Proposer la saisie
        cout << ".......  votre choix ? "; cin >> choixDiaporama;

        // Vérifier la saisie
        if ((choixDiaporama >= 1)&&(choixDiaporama < static_cast<unsigned int>(this->getNombreDiapos())))
        {
            break;
        }
    }

    return choixDiaporama;
}

void Lecteur::chargerImages(Images& images) {
    Image imageACharger("objet", "", "C:\\cartesDisney\\Disney_tapis.gif");
    images.push_back(imageACharger);

    imageACharger = Image("personnage", "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif");
    images.push_back(imageACharger);

    imageACharger = Image("personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif");
    images.push_back(imageACharger);

    imageACharger = Image("animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif");
    images.push_back(imageACharger);

    imageACharger = Image("personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif");
    images.push_back(imageACharger);

    imageACharger = Image("objet", "chateau", "C:\\cartesDisney\\Disney_0.gif");
    images.push_back(imageACharger);

    imageACharger = Image("personnage", "Minnie", "C:\\cartesDisney\\Disney_14.gif");
    images.push_back(imageACharger);

    imageACharger = Image("animal", "Bambi", "C:\\cartesDisney\\Disney_3.gif");
    images.push_back(imageACharger);
}

void Lecteur::chargerDiapos(Images images)
{
    Image image;
    imageDansDiaporama imageDansDiapo;

    // Diaporama par défaut
    Diaporama diapoDefaut("Diaporama par defaut");
    diapoDefaut.setVitesseDefilement(1);

    // Ajout de l'unique image du diaporama par défaut
    imageDansDiapo = imageDansDiaporama(images,0,1);
    diapoDefaut.ajouterImage(imageDansDiapo);

    // Ajout du diaporama dans le tableau de diaporamas
    _touteDiapos.push_back(diapoDefaut);

    // Diaporama de Pantxika
    Diaporama diapoPantxika ("Diaporama Pantxika");
    diapoPantxika.setVitesseDefilement(2);

    // Les images du diaporama de Pantxika
    imageDansDiapo = imageDansDiaporama (images, 4, 3);
    diapoPantxika.ajouterImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama (images,1 ,2);
    diapoPantxika.ajouterImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama (images,2, 4);
    diapoPantxika.ajouterImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama (images,3 ,1);
    diapoPantxika.ajouterImage(imageDansDiapo);

    // Tri des images par leur rang
    diapoPantxika.triCroissantRang();

    // Ajout du diaporama dans le tableau de diaporamas
    _touteDiapos.push_back(diapoPantxika);

    // Diaporama de Thierry
    Diaporama diapoThierry("Diaporama Thierry");
    diapoThierry.setVitesseDefilement(4);

    // Les images du diaporama de Thierry
    imageDansDiapo = imageDansDiaporama(images,4 ,1);
    diapoThierry.ajouterImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,1 ,2);
    diapoThierry.ajouterImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,2 ,3);
    diapoThierry.ajouterImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,3 ,4);
    diapoThierry.ajouterImage(imageDansDiapo);

    // Tri des images par leur rang
    diapoThierry.triCroissantRang();

    // Ajout du diaporama dans le tableau de diaporamas
    _touteDiapos.push_back(diapoThierry);

    // Diaporama de Yann
    Diaporama DiapoYann("Diaporama Yann");
    DiapoYann.setVitesseDefilement(3);

    // Les images du diaporama de Yann
    imageDansDiapo = imageDansDiaporama(images,4 ,2);
    DiapoYann.ajouterImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,1 ,1);
    DiapoYann.ajouterImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,2 ,4);
    DiapoYann.ajouterImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,3 ,3);
    DiapoYann.ajouterImage(imageDansDiapo);

    // Tri des images par leur rang
    DiapoYann.triCroissantRang();

    // Ajout du diaporama dans le tableau de diaporamas
    _touteDiapos.push_back(DiapoYann);


    // Diaporama de Manu
    Diaporama DiapoManu("Diaporama Manu");
    DiapoManu.setVitesseDefilement(1);

    // Les images du diaporama de Manu
    imageDansDiapo = imageDansDiaporama(images,4 ,4);
    DiapoManu.ajouterImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,1 ,3);
    DiapoManu.ajouterImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,2 ,2);
    DiapoManu.ajouterImage(imageDansDiapo);

    imageDansDiapo = imageDansDiaporama(images,3 ,1);
    DiapoManu.ajouterImage(imageDansDiapo);

    // Tri des images par leur rang
    DiapoManu.triCroissantRang();

    // Ajout du diaporama dans le tableau de diaporamas
    _touteDiapos.push_back(DiapoManu);

}

