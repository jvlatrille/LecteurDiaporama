#ifndef PRESENTATION_H
#define PRESENTATION_H
#include <QObject>
#include "modele.h"


class lecteurVue;
class Presentation : public QObject
{
    Q_OBJECT
public:
    explicit Presentation(QObject *parent = nullptr);

private:
    Modele* _leModele;
    lecteurVue* _laVue;

public:
    void setModel(Modele* m);
    void setVue(lecteurVue* v);
    Modele *getModele();
    lecteurVue* getVue();

    //void demanderAllumer();
    //void demanderEteindre();
};

#endif // PRESENTATION_H
