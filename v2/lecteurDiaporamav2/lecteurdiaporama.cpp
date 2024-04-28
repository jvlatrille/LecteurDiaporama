#include "lecteurdiaporama.h"
#include "ui_lecteurdiaporama.h"


lecteurDiaporama::lecteurDiaporama(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lecteurDiaporama)
{
    ui->setupUi(this);

    QObject::connect(ui->bSuivant, SIGNAL(clicked()), this, SLOT(sl_suivant()));
    QObject::connect(ui->bPrecedent, SIGNAL(clicked()), this, SLOT(sl_precedent()));
    QObject::connect(ui->bPause, SIGNAL(clicked()), this, SLOT(sl_pause()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(sl_quitter()));

    //navigation entre les bouton avec tab
    QWidget::setTabOrder({ui->bSuivant, ui->bPrecedent, ui->bPause, ui->bSuivant});
}

lecteurDiaporama::~lecteurDiaporama()
{
    delete ui;
}

void lecteurDiaporama::sl_suivant()
{
    qDebug() << "Image suivante";
}

void lecteurDiaporama::sl_precedent()
{
    qDebug() << "Image précédente";
}

void lecteurDiaporama::sl_pause()
{
    qDebug() << "Défilement mis en pause";
}

void lecteurDiaporama::sl_quitter()
{
    qDebug() << "Quitter";
}
