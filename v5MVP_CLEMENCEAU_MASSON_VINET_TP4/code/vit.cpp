#include "vit.h"
#include "ui_vit.h"

vit::vit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vit)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(handleButtonBoxAccepted()));
}

vit::~vit()
{
    delete ui;
}

void vit::handleButtonBoxAccepted()
{
    int value = ui->sVit->value();  // Remplacez 'sVit' par le nom exact de votre QSpinBox
    qDebug() << "La valeur choisie est :" << value;
}

void vit::setSpine(int valeur)
{
    ui->sVit->setValue(valeur);
}

int vit::valueSpine()
{
    return ui->sVit->value();
}
