#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <QDebug>
#include <QShortcut>
#include <QWidget>
#include "presentation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class lecteurVue; }
QT_END_NAMESPACE

class Presentation;
class lecteurVue : public QMainWindow
{
    Q_OBJECT

private:
    Ui::lecteurVue *ui;
    Presentation * m_MaPresentation;


public:
    lecteurVue(QWidget *parent = nullptr);
    ~lecteurVue();

    void majInterface(Modele::UnEtat e);
    void setPresentation(Presentation *);

public slots:
    void demanderAvancer();
    void demanderReculer();
    void demanderDepartArretAuto();
    void demanderChangerVitesse();
    void demanderChangerModeAutomatique();
    void demanderChangerModeManuel();
    void demanderChargerDiapo();
    void demanderEnleverDiapo();
    void demanderAPropos();
/*
public slots:
    void sl_suivant();
    void sl_precedent();
    void sl_pause();
    void sl_chargerDiapo();
    void sl_quitter();
    void sl_enleverDiapo();
    void sl_vitesseDefilement();
    void sl_modeAuto();
    void sl_modeManuel();
    void sl_aPropos();*/


};
#endif // LECTEURVUE_H
