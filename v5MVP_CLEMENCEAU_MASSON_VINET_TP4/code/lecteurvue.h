#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <QDebug>
#include <QShortcut>
#include <QWidget>
#include "modele.h"
#include "lecteur.h"

QT_BEGIN_NAMESPACE
namespace Ui { class lecteurVue; }
QT_END_NAMESPACE

struct InfosDiaporama {
    unsigned int id;    // identifiant du diaporama dans la BD
    string titre;       // titre du diaporama
    float vitesseDefilement;
};

// Type nécessaire
typedef vector<InfosDiaporama> Diaporamas;


class Presentation;
class lecteurVue : public QMainWindow
{
    Q_OBJECT

private:
    Ui::lecteurVue *ui;
    Presentation * m_MaPresentation;
    Lecteur *monLecteur;
    Modele *modele;
    Diaporamas diaporamas;


public:
    lecteurVue(QWidget *parent = nullptr); // Constructeur
    ~lecteurVue(); // Destructeur

    // Getter
    Presentation * getPresentation() const;

    // Setter
    void setPresentation(Presentation *);

    //Autres méthodes
    void initializeConnections();
    // But : Initialisation des connexions
    void majInterface(Modele::UnEtat);
    // But : Mets à jour l'interface

    void listeDiaporamas(Diaporamas &diaporamas);
    // But : Donne la liste des diaporamas

    int reponse; // Réponse de l'utilisateur pour la vitesse choisie

public slots:
    void demanderAvancer();
    void demanderReculer();
    void demanderChangerVitesse();
    void demanderChangerModeAutomatique();
    void demanderChangerModeManuel();
    void demanderChargerDiapo();
    void recevoirDiaporamaSelectionne(unsigned int diaporamaId);
    void demanderEnleverDiapo();
    void demanderAPropos();
    void quitterApplication();
    void majPresentation(const QString &titreDiapo, const QString &titreImage, const QString &categorie, const QString &rang, const QString &chemin);

signals:
    void diaporamaSelectionne(unsigned int diaporamaId);
};
#endif // LECTEURVUE_H
