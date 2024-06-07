#include "vit.h"
#include "ui_vit.h"

vit::vit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vit)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(boutonOk()));
}

vit::~vit()
{
    delete ui;
}

void vit::boutonOk()
{
    int value = ui->sVit->value();
    qDebug() << "La valeur choisie est :" << value;
}

