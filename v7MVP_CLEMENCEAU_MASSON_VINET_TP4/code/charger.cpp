#include "charger.h"
#include "ui_charger.h"
#include <QDebug>

charger::charger(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::charger)
{
    ui->setupUi(this); // Initialisation de l'interface utilisateur
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &charger::transmettreInformations); // Connecter le bouton d'acceptation à la méthode transmettreInformations
}

charger::~charger()
{
    delete ui;
}

void charger::updateDiaporamas(const Diaporamas &diaporamas)
{
    ui->listDiapos->clear(); // Vider la liste actuelle
    diaporamasDisponibles = diaporamas; // Stocker les diaporamas disponibles
    for (const auto &diapo : diaporamas)
    {
        ui->listDiapos->addItem(QString::fromStdString(diapo.titre)); // Ajouter chaque diaporama à la liste
    }
}

unsigned int charger::getSelectedDiaporamaId() const
{
    int index = ui->listDiapos->currentIndex(); // Obtenir l'index sélectionné
    if (index >= 0 && index < static_cast<int>(diaporamasDisponibles.size()))
    {
        return diaporamasDisponibles.at(index).id; // Retourner l'ID du diaporama sélectionné
    }
    return 0; // Retourner un ID par défaut en cas d'erreur
}

void charger::transmettreInformations()
{
    unsigned int diaporamaId = getSelectedDiaporamaId(); // Obtenir l'ID du diaporama sélectionné
    qDebug() << "Diaporama sélectionné ID:" << diaporamaId; // Afficher l'ID pour le débogage
    emit diaporamaSelectionne(diaporamaId); // Émettre le signal
}
