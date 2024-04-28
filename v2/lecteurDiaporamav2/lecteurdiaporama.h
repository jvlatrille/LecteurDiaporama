#ifndef LECTEURDIAPORAMA_H
#define LECTEURDIAPORAMA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class lecteurDiaporama; }
QT_END_NAMESPACE

class lecteurDiaporama : public QMainWindow
{
    Q_OBJECT

public:
    lecteurDiaporama(QWidget *parent = nullptr);
    ~lecteurDiaporama();

private:
    Ui::lecteurDiaporama *ui;
};
#endif // LECTEURDIAPORAMA_H
