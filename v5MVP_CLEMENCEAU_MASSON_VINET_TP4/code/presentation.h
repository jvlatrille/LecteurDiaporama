#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include "modele.h"
#include "lecteurVue.h"
#include "vit.h"
#include <QTimer>
#include <QDebug>

class Presentation : public QObject
{
    Q_OBJECT
private:
    Modele* _leModele;
    lecteurVue* _laVue;
    QTimer* timer;
    int intervalleTimer = 1000;

public:
    Presentation();
    ~Presentation();

    void setModel(Modele* m);
    void setVue(lecteurVue* v);
    Modele *getModele();
    lecteurVue *getVue();

    ImageDansDiaporama* getImageActuelle();
    Diaporama * getDiapoActuel();
    int getVitesse();

    void demanderAvancer();
    void demanderReculer();
    void autoAdvance();
    void demanderChangerVitesse(vit* v);
    void demanderChangerModeAutomatique();
    void demanderChangerModeManuel();
    void demanderChargerDiapo();
    void demanderEnleverDiapo();
    void avancerBouble();
    void ajusterVitesseDiaporama(int vitesse);

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
