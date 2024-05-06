#include "presentation.h"
#include "lecteurvue.h"
#include "ui_lecteurvue.h"

Presentation::Presentation(QObject *parent)
    : QObject{parent}
{

}

void Presentation::setModel(Modele *m)
{
    _leModele = m;
}

void Presentation::setVue(lecteurVue *v)
{
    _laVue = v;
}

Modele *Presentation::getModele()
{
    return _leModele;
}

lecteurVue *Presentation::getVue()
{
    return _laVue;
}

/*void Presentation::demanderAllumer()
{
    _leModele->allumer();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "Présentation solicitée par la vue pour allumer l'lecteur";
}

void Presentation::demanderEteindre()
{
    _leModele->eteindre();
    _laVue->majInterface(_leModele->getEtat());
    qDebug() << "Présentation solicitée par la vue pour éteindre l'lecteur";
}*/
