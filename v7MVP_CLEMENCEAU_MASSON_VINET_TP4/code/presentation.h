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
    Presentation(); // Constructeur
    ~Presentation(); // Destructeur

    // Getters
    Modele *getModele();
    lecteurVue *getVue();
    ImageDansDiaporama* getImageActuelle();
    Diaporama * getDiapoActuel();
    int getVitesse();

    // Setters
    void setModel(Modele* m);
    void setVue(lecteurVue* v);

    // Autres méthodes
    void demanderAvancer();
    void demanderReculer();
    void autoAdvance();
    void demanderChangerVitesse(vit* v);
    void demanderChangerModeAutomatique();
    void demanderChangerModeManuel();
    void demanderChargerDiapo(unsigned int id, const QString &titre, int vitesseDefilement);
    void demanderEnleverDiapo();
    void avancerBouble();
    void ajusterVitesseDiaporama(int vitesse);
};

#endif // PRESENTATION_H
