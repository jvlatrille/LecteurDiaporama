#include "presentation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lecteurVue w;
    qDebug() << "Everything is set";
    Lecteur* l = new Lecteur();
    qDebug() << "Everything is set";
    Modele* m = new Modele();
    qDebug() << "Everything is set";
    Presentation *p = new Presentation();
    qDebug() << "Everything is set";

    p->setModel(m);
    p->setVue(&w);
    w.setPresentation(p);
    l->changerDiaporama(2, "Diapo par défaut", 2);
    m->setLecteur(l);
    qDebug() << "Final";

    w.initializeConnections();

    w.show();
    return a.exec();
}
