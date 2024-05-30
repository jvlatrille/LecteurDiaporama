#include "charger.h"
#include "ui_charger.h"
#include <QDebug>

charger::charger(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::charger)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &charger::transmettreInformations);
}

charger::~charger()
{
    delete ui;
}

void charger::updateDiaporamas(const Diaporamas &diaporamas)
{
    ui->listDiapos->clear();
    diaporamasDisponibles = diaporamas; // Stocker les diaporamas disponibles
    for (const auto &diapo : diaporamas)
    {
        ui->listDiapos->addItem(QString::fromStdString(diapo.titre));
    }
}

unsigned int charger::getSelectedDiaporamaId() const
{
    int index = ui->listDiapos->currentIndex();
    if (index >= 0 && index < static_cast<int>(diaporamasDisponibles.size()))
    {
        return diaporamasDisponibles.at(index).id;
    }
    return 0; // Retourner un ID par défaut en cas d'erreur
}

void charger::transmettreInformations()
{
    unsigned int diaporamaId = getSelectedDiaporamaId();
    qDebug() << "Diaporama sélectionné ID:" << diaporamaId;
    emit diaporamaSelectionne(diaporamaId); // Émettre le signal
}
