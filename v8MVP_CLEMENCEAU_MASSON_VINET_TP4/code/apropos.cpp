#include "apropos.h"
#include "ui_apropos.h"

apropos::apropos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::apropos)
{
    ui->setupUi(this);
}

apropos::~apropos()
{
    delete ui;
}
