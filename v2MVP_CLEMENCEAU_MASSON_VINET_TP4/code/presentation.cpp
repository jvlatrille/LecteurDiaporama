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
    emit s_avancer();
}

void Presentation::demanderReculer()
{
    qDebug() << "Demande à reculer";
    emit s_reculer();
}

void Presentation::demanderDepartArretAuto()
{
    qDebug() << "Demande à arrêter / démarer diapo (en fonction de l'etat)";
    emit s_departArret();
}

void Presentation::demanderChangerVitesse()
{
    qDebug() << "Demande à changer la vitesse";
        emit s_changerVitesse();
}

void Presentation::demanderChangerMode()
{
    qDebug() << "Demande à changer de mode";
    emit s_changerMode();
}


