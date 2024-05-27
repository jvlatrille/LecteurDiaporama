#include "vit.h"
#include "ui_vit.h"

vit::vit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vit)
{
    ui->setupUi(this);
}

vit::~vit()
{
    delete ui;
}

void vit::setSpine(int valeur)
{
    ui->sVit->setValue(valeur);
}

int vit::valueSpine()
{
    return ui->sVit->value();
}
