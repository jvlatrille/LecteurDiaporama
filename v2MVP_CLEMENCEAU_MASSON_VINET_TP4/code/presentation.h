#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include "modele.h"
#include "lecteurVue.h"

class Presentation : public QObject
{
    Q_OBJECT
public:
    explicit Presentation(QObject *parent = nullptr);

private:
    Modele* _leModele;
    lecteurVue* _laVue;

public:
    Modele* getModele();
    lecteurVue* getVue();

    void setModel(Modele* m);
    void setVue(lecteurVue* v);

public slots:
    void demanderAvancer();
    void demanderReculer();
    void demanderArret();
};

#endif // PRESENTATION_H
