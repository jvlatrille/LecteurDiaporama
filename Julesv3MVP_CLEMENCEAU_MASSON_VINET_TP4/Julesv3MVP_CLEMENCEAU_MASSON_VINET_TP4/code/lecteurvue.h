#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <QDebug>
#include <QShortcut>
#include <QWidget>
#include "lecteur.h"

QT_BEGIN_NAMESPACE
namespace Ui { class lecteurVue; }
QT_END_NAMESPACE

class Presentation;
class lecteurVue : public QMainWindow
{
    Q_OBJECT

private:
    Ui::lecteurVue *ui;
    Lecteur *l;

public:
    lecteurVue(QWidget *parent = nullptr);
    ~lecteurVue();

public slots:
    void sl_suivant();
    void sl_precedent();
    void sl_departArret();
    void sl_chargerDiapo();
    void sl_quitter();
    void sl_enleverDiapo();
    void sl_vitesseDefilement();
    void sl_modeAuto();
    void sl_modeManuel();
    void sl_aPropos();

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
#endif // LECTEURVUE_H
