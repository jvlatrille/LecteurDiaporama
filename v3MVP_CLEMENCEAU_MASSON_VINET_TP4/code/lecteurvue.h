#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <QDebug>
#include <QShortcut>
#include <QWidget>
#include "modele.h"

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
    Presentation * getPresentation() const;
    void majInterface(Modele::UnEtat e);
    void majPresentation(Diaporama * d);
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
    void quitterApplication();
};
#endif // LECTEURVUE_H
