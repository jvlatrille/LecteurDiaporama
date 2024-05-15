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

void Presentation::demanderAvancer()
{
    qDebug() << "Demande d'avancer";
    _leModele->avancer();
    _laVue->majInterface(_leModele->getEtat());
}

void Presentation::demanderReculer()
{
    qDebug() << "Demande à reculer";
    _leModele->reculer();
    _laVue->majInterface(_leModele->getEtat());
}

void Presentation::demanderDepartArretAuto()
{
    qDebug() << "Demande à arrêter / démarer diapo (en fonction de l'etat)";
    _leModele->departArretAuto();
    _laVue->majInterface(_leModele->getEtat());
}

void Presentation::demanderChangerVitesse()
{
    qDebug() << "Demande à changer la vitesse";
    _leModele->changerVitesse();
    _laVue->majInterface(_leModele->getEtat());
}

void Presentation::demanderChangerModeAutomatique()
{
    qDebug() << "Demande à changer de mode en automatique";
    _leModele->etatAutomatique();
    _laVue->majInterface(_leModele->getEtat());
}

void Presentation::demanderChangerModeManuel()
{
    qDebug() << "Demande à changer de mode en Manuel";
    _leModele->etatManuel();
    _laVue->majInterface(_leModele->getEtat());
}

void Presentation::demanderChargerDiapo()
{
    qDebug() << "Demande à charger un nouveau diaporama";
    _leModele->chargerDiapo();
    _laVue->majInterface(_leModele->getEtat());
}

void Presentation::demanderEnleverDiapo()
{
    qDebug() << "Demande à enlever le diaporama courrant";
    _leModele->enleverDiapo();
    _laVue->majInterface(_leModele->getEtat());
}

void Presentation::demanderAPropos()
{
    qDebug() << "Demande à afficher la fenêtre a propos de l'application";
    _leModele->aPropos();
    _laVue->majInterface(_leModele->getEtat());
}
