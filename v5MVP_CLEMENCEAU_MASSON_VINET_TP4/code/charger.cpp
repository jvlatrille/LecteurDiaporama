#include "charger.h"
#include "ui_charger.h"
#include "modele.h"

charger::charger(Diaporamas& d, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::charger)
    , infoDiapo(d)
{
    ui->setupUi(this);

    for (unsigned int i = 0 ; i < d.size(); i++)
    {
        QString id = QString::number(d[i].id);
        QString titre = QString::fromStdString(d[i].titre);
        QString chainePourAffichage = id + " - " + titre;
        ui->listDiapos->addItem(chainePourAffichage);
    }

    QObject::connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &charger::transmettreInformations);
}

charger::~charger()
{
    delete ui;
}

Diaporamas charger::getInfosDiapo() const
{
    return infoDiapo;
}

void charger::transmettreInformations()
{
    int index = ui->listDiapos->currentIndex();
    if (index >= 0 && index < static_cast<int>(infoDiapo.size())) {
        InfosDiaporama diapoChoisi = infoDiapo[index];
        emit envoyerInfos(diapoChoisi);
    }
}

