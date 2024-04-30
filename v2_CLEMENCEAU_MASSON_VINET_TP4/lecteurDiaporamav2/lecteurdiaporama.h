#ifndef LECTEURDIAPORAMA_H
#define LECTEURDIAPORAMA_H

#include <QMainWindow>
#include <QDebug>
#include <QShortcut>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class lecteurDiaporama; }
QT_END_NAMESPACE

class lecteurDiaporama : public QMainWindow
{
    Q_OBJECT

public:
    lecteurDiaporama(QWidget *parent = nullptr);
    ~lecteurDiaporama();

public slots:
    void sl_suivant();
    void sl_precedent();
    void sl_pause();
    void sl_quitter();

private:
    Ui::lecteurDiaporama *ui;
};
#endif // LECTEURDIAPORAMA_H
