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

void Presentation::demanderAvancer()
{
    if (!_leModele) {
        qDebug() << "_leModele est nul";
        return;
    }
    if (!_laVue) {
        qDebug() << "_laVue est nul";
        return;
    }
    qDebug()<< "J'avance 3";
    _leModele->avancer();
    qDebug()<< "J'avance 4";

    Lecteur* lecteur = _leModele->getLecteur();
    if (!lecteur)
    {
        qDebug() << "Lecteur est nul";
        return;
    }
    Diaporama * diapo = lecteur->getDiaporama();
    if (!diapo) {
        qDebug() << "Diaporama est nul";
        return;
    }

    _laVue->majPresentation(diapo);
    qDebug() << "L'image avance";
}


void Presentation::demanderReculer()
{
    if (!_leModele) {
        qDebug() << "_leModele est nul";
        return;
    }
    if (!_laVue) {
        qDebug() << "_laVue est nul";
        return;
    }

    _leModele->reculer();

    auto diapo = _leModele->getDiaporama();
    if (!diapo) {
        qDebug() << "Diaporama est nul";
        return;
    }

    _laVue->majPresentation(diapo);
    qDebug() << "L'image recule";
}

void Presentation::demanderDepartArretAuto()
{
    _leModele->departArretAuto();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "Le défilement d'image se met en pause / avance en mode auto";
}

void Presentation::demanderChangerVitesse()
{

    _leModele->changerVitesse();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "La fenêtre pour changer la vitesse apparait";
}

void Presentation::demanderChangerModeAutomatique()
{
    _leModele->etatAutomatique();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "Le mode change en automatique";
}

void Presentation::demanderChangerModeManuel()
{
    _leModele->etatManuel();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "Le mode change en manuel";
}

void Presentation::demanderChargerDiapo()
{
    _leModele->chargerDiapo();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "On charges une nouvelle diapo";
}

void Presentation::demanderEnleverDiapo()
{
    _leModele->enleverDiapo();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "On retire le diapo courant";
}

void Presentation::demanderAPropos()
{
    qDebug() << "Demande à afficher la fenêtre a propos de l'application";
    _leModele->aPropos();
    _laVue->majInterface(_leModele->getEtat());
}
