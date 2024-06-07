#ifndef CHARGER_H
#define CHARGER_H

#include <QDialog>
#include <QComboBox>
#include "lecteurvue.h"

namespace Ui {
class charger;
}

class charger : public QDialog
{
    Q_OBJECT

public:
    explicit charger(QWidget *parent = nullptr);
    ~charger(); // Destructeur

    void updateDiaporamas(const Diaporamas &diaporamas); // Mise à jour de la liste des diaporamas disponibles
    unsigned int getSelectedDiaporamaId() const; // Récupère l'ID du diaporama sélectionné dans la fenêtre


signals:
    void diaporamaSelectionne(unsigned int diaporamaId); // Signal émis quand un diaporama est sélectionné

private slots:
    void transmettreInformations(); // Transmet les infos du diaporama sélectionné

private:
    Ui::charger *ui;
    Diaporamas diaporamasDisponibles;
};

#endif // CHARGER_H
