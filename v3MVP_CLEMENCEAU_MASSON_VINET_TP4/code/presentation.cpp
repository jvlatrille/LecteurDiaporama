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
    _leModele->avancer();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "Demande d'avancer";
}

void Presentation::demanderReculer()
{
    _leModele->reculer();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "Demande à reculer";
}

void Presentation::demanderDepartArretAuto()
{
    _leModele->departArretAuto();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "Demande à arrêter / démarer diapo (en fonction de l'etat)";
}

void Presentation::demanderChangerVitesse()
{
    _leModele->changerVitesse();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "Demande à changer la vitesse";
}

void Presentation::demanderChangerModeAutomatique()
{
    _leModele->etatAutomatique();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "Demande à changer de mode en automatique";
}

void Presentation::demanderChangerModeManuel()
{
    _leModele->etatManuel();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "Demande à changer de mode en Manuel";
}

void Presentation::demanderChargerDiapo()
{
    _leModele->chargerDiapo();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "Demande à charger un nouveau diaporama";
}

void Presentation::demanderEnleverDiapo()
{
    _leModele->enleverDiapo();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "Demande à enlever le diaporama courrant";
}

void Presentation::demanderAPropos()
{
    _leModele->aPropos();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "Demande à afficher la fenêtre a propos de l'application";
}
