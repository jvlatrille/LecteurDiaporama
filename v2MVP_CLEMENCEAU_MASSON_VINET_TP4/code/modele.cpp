#include "modele.h"

Modele::Modele(UnEtat e, QObject *parent)
    : QObject{parent}, _etat(e)
{
}

/*void Modele::allumer()
{
    _etat = UnEtat::allume;
}

void Modele::eteindre()
{
    _etat = UnEtat::eteint;
}

Modele::UnEtat Modele::getEtat()
{
    return _etat;
}*/
