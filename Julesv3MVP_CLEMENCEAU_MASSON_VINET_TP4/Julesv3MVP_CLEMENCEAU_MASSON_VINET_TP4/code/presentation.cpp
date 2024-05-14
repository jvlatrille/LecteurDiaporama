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
    if (!lecteurVide())
    {
        if (getPosImageCourante() == nbImages()- 1)
        {
            setPosImageCourante(0);
        }
        else {
            setPosImageCourante(getPosImageCourante() + 1);
        }
    }
    emit s_avancer();
}

void Presentation::demanderReculer()
{
    qDebug() << "Demande à reculer";
    if (!lecteurVide())
    {
        if (getPosImageCourante() == 0)
        {
            setPosImageCourante(nbImages()- 1);
        }
        else {
            setPosImageCourante(getPosImageCourante() - 1);
        }
    }
    emit s_reculer();
}

void Presentation::demanderDepartArretAuto()
{
    qDebug() << "Demande à arrêter / démarer diapo (en fonction de l'etat)";
    // Voir avec etet diapo si auto ou non etc...
    emit s_departArret();
}

void Presentation::demanderChangerVitesse()
{
    qDebug() << "Demande à changer la vitesse";
    //
    emit s_changerVitesse();
}

void Presentation::demanderChangerModeAutomatique()
{
    qDebug() << "Demande à changer de mode en automatique";
    emit s_changerModeAuto();
}

void Presentation::demanderChangerModeManuel()
{
    qDebug() << "Demande à changer de mode en Manuel";
    emit s_changerModeManuel();
}

void Presentation::demanderChargerDiapo()
{
    qDebug() << "Demande à charger un nouveau diaporama";
    emit s_chargerDiapo();
}

void Presentation::demanderQuitter()
{
    qDebug() << "Demande à quitter l'application";
    emit s_quitter();
}

void Presentation::demanderEnleverDiapo()
{
    qDebug() << "Demande à enlever le diaporama courrant";
    emit s_enleverDiapo();
}

void Presentation::demanderAPropos()
{
    qDebug() << "Demande à afficher la page a propos de l'application";
    emit s_aPropos();
}
