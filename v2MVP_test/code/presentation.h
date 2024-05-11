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
    Presentation();

    Modele* getModele();
    lecteurVue* getVue();

    void setModel(Modele* m);
    void setVue(lecteurVue* v);

public slots:
    void demanderAvancer();
    void demanderReculer();
    void demanderDepart();  // Départ mode auto
    void demanderArret();  // Arrêt mode auto
    void demanderChangerVitesse();
    void demanderModeManuel();
    void demanderModeAutomatique();

signals:
    void avancerDiapo();
    void reculerDiapo();
};

#endif // PRESENTATION_H
