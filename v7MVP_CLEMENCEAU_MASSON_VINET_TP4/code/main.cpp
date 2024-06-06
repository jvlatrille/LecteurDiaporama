#include "presentation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Initialiser l'application Qt
    lecteurVue w; // Créer une instance de la vue
    Lecteur* l = new Lecteur(); // Créer une instance du lecteur
    Modele* m = new Modele(); // Créer une instance du modèle
    Presentation *p = new Presentation(); // Créer une instance de la présentation

    p->setModel(m); // Associer le modèle à la présentation
    p->setVue(&w); // Associer la vue à la présentation
    m->setEtat(Modele::defaut); // Définir l'état initial du modèle
    w.majInterface(m->getEtat()); // Mettre à jour l'interface en fonction de l'état du modèle
    w.setPresentation(p); // Associer la présentation à la vue
    m->setLecteur(l); // Associer le lecteur au modèle

    w.initializeConnections(); // Initialiser les connexions entre la vue et la présentation

    w.show(); // Afficher la fenêtre principale
    return a.exec(); // Lancer la boucle d'événements de l'application
}
