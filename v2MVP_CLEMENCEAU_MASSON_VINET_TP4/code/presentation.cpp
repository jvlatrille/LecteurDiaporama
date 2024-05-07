#include "ui_lecteurvue.h"
#include "presentation.h"

Presentation::Presentation(QObject *parent)
    : QObject(parent), _leModele(nullptr), _laVue(nullptr)
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

void Presentation::demanderAvancer()
{
    if (_leModele)
    {
        _leModele->avancer();
        // Mettre à jour l'interface utilisateur via la vue
    }
}

void Presentation::demanderReculer()
{
    if (_leModele)
    {
        _leModele->reculer();
        // Mettre à jour l'interface utilisateur via la vue
    }
}

void Presentation::demanderArret()
{
    // Demander l'arrêt de la lecture du diaporama s'il est en automatique
}
