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

