#include "lecteurdiaporama.h"
#include "ui_lecteurdiaporama.h"

lecteurDiaporama::lecteurDiaporama(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lecteurDiaporama)
{
    ui->setupUi(this);
}

lecteurDiaporama::~lecteurDiaporama()
{
    delete ui;
}
