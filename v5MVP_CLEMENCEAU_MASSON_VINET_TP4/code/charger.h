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
    ~charger();

    void updateDiaporamas(const Diaporamas &diaporamas);
    unsigned int getSelectedDiaporamaId() const;


signals:
    void diaporamaSelectionne(unsigned int diaporamaId);

private slots:
    void transmettreInformations();

private:
    Ui::charger *ui;
    Diaporamas diaporamasDisponibles; // Stocker les diaporamas disponibles pour récupérer l'id
};

#endif // CHARGER_H
