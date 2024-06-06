#include "presentation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lecteurVue w;
    Lecteur* l = new Lecteur();
    Modele* m = new Modele();
    Presentation *p = new Presentation();

    p->setModel(m);
    p->setVue(&w);
    m->setEtat(Modele::defaut);
    w.majInterface(m->getEtat());
    w.setPresentation(p);
    m->setLecteur(l);

    w.initializeConnections();

    w.show();
    return a.exec();
}
