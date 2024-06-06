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
    lecteurVue(QWidget *parent = nullptr);
    ~lecteurVue();
    Presentation * getPresentation() const; // Récupère la présentation
    void setPresentation(Presentation *); // Définit la présentation

    void initializeConnections(); // Initialise les connexions des signaux et slots
    void majInterface(Modele::UnEtat); // Met à jour les boutons en fonction de l'état
    int reponse; // Variable pour stocker la réponse
    void listeDiaporamas(Diaporamas &diaporamas); // Liste les diaporamas disponibles

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
    void diaporamaSelectionne(unsigned int diaporamaId); // Signal émis quand un diaporama est sélectionné avec l'ID du diapo
};
#endif // LECTEURVUE_H
