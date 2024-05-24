#include "presentation.h"

Presentation::Presentation()
{
    _leModele = nullptr;
    _laVue = nullptr;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Presentation::avancerBouble);
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
        qDebug() << "_leModele est nul";
        return;
    }
    if (!_laVue) {
        qDebug() << "_laVue est nul";
        return;
    }
    if(getModele()->getEtat() == Modele::automatique)
    {
        demanderChangerModeManuel();
    }
    else{
        _leModele->avancer();
    }


    Diaporama *diapo = _leModele->getLecteur()->getDiaporama();
    if (!diapo) {
        qDebug() << "Diaporama est nul";
        return;
    }
    qDebug() << "L'image avance";
}

void Presentation::demanderReculer() {
    if (!_leModele) {
        qDebug() << "_leModele est nul";
        return;
    }
    if (!_laVue) {
        qDebug() << "_laVue est nul";
        return;
    }
    if(getModele()->getEtat() == Modele::automatique)
    {
        demanderChangerModeManuel();
    }
    else{
        _leModele->reculer();
    }


    Diaporama *diapo = _leModele->getLecteur()->getDiaporama();
    if (!diapo) {
        qDebug() << "Diaporama est nul";
        return;
    }
    qDebug() << "L'image recule";
}

void Presentation::autoAdvance() {
    _leModele->avanceAuto();  // Fait avancer le modèle automatiquement
}



void Presentation::demanderChangerVitesse()
{

    _leModele->changerVitesse();
    qDebug() << "La fenêtre pour changer la vitesse apparait";
}

void Presentation::demanderChangerModeAutomatique()
{

    _leModele->setEtat(Modele::automatique);

    timer->start(1000);



    qDebug() << "Le mode change en automatique";
}

void Presentation::demanderChangerModeManuel()
{
    _leModele->setEtat(Modele::manuel);
    timer->stop();  // Arrêter le timer lorsque le mode est changé en manuel.
    disconnect(timer, &QTimer::timeout, _leModele, &Modele::avanceAuto);
}

void Presentation::demanderChargerDiapo()
{
    _leModele->chargerDiapo();
    qDebug() << "On charges une nouvelle diapo";
}

void Presentation::demanderEnleverDiapo()
{
    _leModele->enleverDiapo();
    qDebug() << "On retire le diapo courant";
}

void Presentation::demanderAPropos()
{
    qDebug() << "Demande à afficher la fenêtre a propos de l'application";
    _leModele->aPropos();

}

void Presentation::avancerBouble()
{
    _leModele->avancer();
}
