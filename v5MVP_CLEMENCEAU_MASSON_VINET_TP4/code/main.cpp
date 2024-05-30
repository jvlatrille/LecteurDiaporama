#include "presentation.h"
#include <QApplication>


struct InfosDiaporama {
    unsigned int id;    // identifiant du diaporama dans la BD
    string titre;       // titre du diaporama
    unsigned int vitesseDefilement;
};
typedef vector<InfosDiaporama> Diaporamas;


/* Spécifications des sous-programmes utilisés par le main()
 * ---------------------------------------------------*/
void charger (Diaporamas& pDiaporamas);

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
    qDebug() << "Final";

    w.initializeConnections();

    w.show();
    return a.exec();
}
