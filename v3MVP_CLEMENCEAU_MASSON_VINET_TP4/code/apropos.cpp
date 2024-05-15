#include "apropos.h"
#include "ui_apropos.h"

aPropos::aPropos(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::aPropos)
{
    ui->setupUi(this);
}

aPropos::~aPropos()
{
    delete ui;
}
