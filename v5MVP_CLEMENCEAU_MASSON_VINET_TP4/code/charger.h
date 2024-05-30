#ifndef CHARGER_H
#define CHARGER_H

#include <QDialog>
#include <QComboBox>
#include "modele.h"

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

private:
    Ui::charger *ui;
};

#endif // CHARGER_H
