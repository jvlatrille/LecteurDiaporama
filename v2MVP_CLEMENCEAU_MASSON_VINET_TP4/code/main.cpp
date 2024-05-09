#include "lecteurvue.h"
#include "modele.h"
#include "presentation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lecteurVue w;
    Modele* m = new Modele();
    Presentation *p = new Presentation();

    // w.setPresentation(p);
    p->setModel(m);
    p->setVue(&w);

    w.show();
    return a.exec();
}
