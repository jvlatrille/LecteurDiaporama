#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <QDebug>
#include <QShortcut>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class lecteurDiaporama; }
QT_END_NAMESPACE

class lecteurDiaporama : public QMainWindow
{
    Q_OBJECT

public:
    lecteurDiaporama(QWidget *parent = nullptr);
    ~lecteurDiaporama();

public slots:
    void sl_suivant();
    void sl_precedent();
    void sl_pause();
    void sl_chargerDiapo();
    void sl_quitter();
    void sl_enleverDipo();
    void sl_vitesseDefilement();
    void sl_modeAuto();
    void sl_modeManuel();
    void sl_aPropos();

private:
    Ui::lecteurDiaporama *ui;

};
#endif // LECTEURVUE_H
