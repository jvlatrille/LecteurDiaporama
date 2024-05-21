#include "presentation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lecteurVue w;
    Lecteur l;
    Modele* m = new Modele();
    Presentation *p = new Presentation();

    p->setModel(m);
    p->setVue(&w);
    w.setPresentation(p);
    m->setLecteur(l);


    w.show();
    return a.exec();
}
