#include "presentation.h"

Presentation::Presentation()
{
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

    _leModele->avancer();

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

    _leModele->reculer();

    Diaporama *diapo = _leModele->getLecteur()->getDiaporama();
    if (!diapo) {
        qDebug() << "Diaporama est nul";
        return;
    }

    qDebug() << "L'image recule";
}


void Presentation::demanderDepartArretAuto()
{
    _leModele->departArretAuto();
    qDebug() << "Le défilement d'image se met en pause / avance en mode auto";
}

void Presentation::demanderChangerVitesse()
{

    _leModele->changerVitesse();
    qDebug() << "La fenêtre pour changer la vitesse apparait";
}

void Presentation::demanderChangerModeAutomatique()
{
    _leModele->etatAutomatique();
    qDebug() << "Le mode change en automatique";
}

void Presentation::demanderChangerModeManuel()
{
    _leModele->etatManuel();
    qDebug() << "Le mode change en manuel";
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
