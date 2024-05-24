#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include "modele.h"
#include "lecteurVue.h"
#include <QTimer>
#include <QDebug>

class Presentation : public QObject
{
    Q_OBJECT
private:
    Modele* _leModele;
    lecteurVue* _laVue;
    QTimer* timer;

public:
    Presentation();
    ~Presentation();

    void setModel(Modele* m);
    void setVue(lecteurVue* v);
    Modele *getModele();
    lecteurVue *getVue();

    ImageDansDiaporama* getImageActuelle();
    Diaporama * getDiapoActuel();

    void demanderAvancer();
    void demanderReculer();
    void autoAdvance();
    void demanderChangerVitesse();
    void demanderChangerModeAutomatique();
    void demanderChangerModeManuel();
    void demanderChargerDiapo();
    void demanderEnleverDiapo();
    void demanderAPropos();
    void avancerBouble();

    /*
signals:
    void s_avancer();
    void s_reculer();
    void s_departArret();
    void s_changerVitesse();
    void s_changerModeAuto();
    void s_changerModeManuel();
    void s_chargerDiapo();
    void s_quitter();
    void s_enleverDiapo();
    void s_aPropos();*/

};

#endif // PRESENTATION_H