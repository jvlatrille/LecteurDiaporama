#include "charger.h"
#include "ui_charger.h"

charger::charger(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::charger)
{
    ui->setupUi(this);
}

charger::~charger()
{
    delete ui;
}

void charger::updateDiaporamas(const Diaporamas &diaporamas)
{
    ui->listDiapos->clear();
    for (const auto &diapo : diaporamas)
    {
        ui->listDiapos->addItem(QString::fromStdString(diapo.titre));
    }
}
