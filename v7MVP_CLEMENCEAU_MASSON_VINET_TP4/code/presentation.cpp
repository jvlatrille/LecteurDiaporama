#include "presentation.h"

Presentation::Presentation()
{
    _leModele = nullptr; // Initialiser le modèle à nullptr
    _laVue = nullptr; // Initialiser la vue à nullptr

    timer = new QTimer(this); // Créer un nouveau timer
    connect(timer, &QTimer::timeout, this, &Presentation::avancerBouble); // Connecter le signal timeout du timer à la méthode avancerBouble
}

Presentation::~Presentation() {
}

Modele *Presentation::getModele()
{
    return _leModele;
}

lecteurVue *Presentation::getVue()
{
    return _laVue;
}

void Presentation::setModel(Modele *m)
{
    _leModele = m;
}

void Presentation::setVue(lecteurVue *v)
{
    _laVue = v;
}

ImageDansDiaporama* Presentation::getImageActuelle()
{
    return _leModele->getDiaporama()->getImageCourante();
}

Diaporama *Presentation::getDiapoActuel()
{
    return getModele()->getDiaporama();
}


void Presentation::demanderAvancer() {
    if (!_leModele) {
        qDebug() << "_leModele est nul"; // Log pour indiquer que le modèle est nul
        return;
    }
    if (!_laVue) {
        qDebug() << "_laVue est nul"; // Log pour indiquer que la vue est nulle
        return;
    }
    if(getModele()->getEtat() == Modele::automatique)
    {
        demanderChangerModeManuel(); // Changer en mode manuel si l'état est automatique
    }
    else{
        _leModele->avancer(); // Appeler la méthode avancer du modèle
    }

    Diaporama* diapo = _leModele->getLecteur()->getDiaporama();
    if (!diapo) {
        qDebug() << "Diaporama est nul"; // Log pour indiquer que le diaporama est nul
        return;
    }
    qDebug() << "L'image avance"; // Log pour indiquer que l'image a avancé
}

void Presentation::demanderReculer() {
    if (!_leModele) {
        qDebug() << "_leModele est nul"; // Log pour indiquer que le modèle est nul
        return;
    }
    if (!_laVue) {
        qDebug() << "_laVue est nul"; // Log pour indiquer que la vue est nulle
        return;
    }
    if(getModele()->getEtat() == Modele::automatique)
    {
        demanderChangerModeManuel(); // Changer en mode manuel si l'état est automatique
    }
    else{
        _leModele->reculer(); // Appeler la méthode reculer du modèle
    }

    Diaporama* diapo = _leModele->getLecteur()->getDiaporama();
    if (!diapo) {
        qDebug() << "Diaporama est nul"; // Log pour indiquer que le diaporama est nul
        return;
    }
    qDebug() << "L'image recule"; // Log pour indiquer que l'image a reculé
}

void Presentation::autoAdvance() {
    _leModele->avanceAuto();  // Fait avancer le modèle automatiquement
}



void Presentation::demanderChangerVitesse(vit* v)
{
    _leModele->changerVitesse(v);
    qDebug() << "La fenêtre pour changer la vitesse apparait";
}

void Presentation::demanderChangerModeAutomatique()
{
    _leModele->setEtat(Modele::automatique); // Définir l'état comme automatique
    _laVue->majInterface(_leModele->getEtat()); // Mettre à jour l'interface de la vue

    int vitesseActuelle = _leModele->getVitesseDefilement(); // Récupérer la vitesse actuelle du modèle
    ajusterVitesseDiaporama(vitesseActuelle); // Ajuster la vitesse du diaporama
    qDebug() << "Le mode change en automatique"; // Log pour indiquer que le mode a changé en automatique
}

void Presentation::ajusterVitesseDiaporama(int vitesse) {
    if (vitesse <= 0) {
        qDebug() << "Valeur de vitesse non valide, réglée à 1 par défaut";
        vitesse = 1; // Pour éviter la division par zéro ou un intervalle trop court
    }

    intervalleTimer = 1000 / vitesse; // Transformer la vitesse en intervalle adapté pour le timer
    if (intervalleTimer < 100) {
        intervalleTimer = 1000; // Garantir un minimum pour éviter le clignotement ou le crash
    }

    timer->start(intervalleTimer); // Démarrer le timer avec l'intervalle ajusté
    qDebug() << "Vitesse du diaporama ajustée à un intervalle de" << intervalleTimer << "millisecondes";
}



int Presentation::getVitesse(){
    return intervalleTimer;
}

void Presentation::demanderChangerModeManuel()
{
    // Arreter le timer mode auto
    timer->stop();  // Arrêter le timer lorsque le mode est changé en manuel.

    // Changer l'état & majI
    _leModele->setEtat(Modele::manuel);
    _laVue->majInterface(_leModele->getEtat());
    disconnect(timer, &QTimer::timeout, _leModele, &Modele::avanceAuto);
}


void Presentation::demanderChargerDiapo(unsigned int id, const QString &titre, int vitesseDefilement) {
    _leModele->chargerDiapo(id, titre, vitesseDefilement);
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "On charge une nouvelle diapo";
}


void Presentation::demanderEnleverDiapo()
{
    _leModele->enleverDiapo();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "On retire le diapo courant";
}


void Presentation::avancerBouble()
{
    _leModele->avancer();
}
