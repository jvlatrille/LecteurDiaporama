#ifndef CHARGER_H
#define CHARGER_H

#include <QDialog>
#include "modele.h"

namespace Ui {
class charger;
}

class charger : public QDialog
{
    Q_OBJECT

public:
    charger(Diaporamas&, QWidget *parent = nullptr);
    explicit charger(QWidget *parent = nullptr);
    ~charger();
    Diaporamas getInfosDiapo() const;

private:
    Ui::charger *ui;
    Diaporamas infoDiapo;
    InfosDiaporama infoDiapoActuel;


private slots:
    void transmettreInformations();

signals:
    void envoyerInfos(InfosDiaporama);


};

#endif // CHARGER_H
