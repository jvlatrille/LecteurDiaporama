#ifndef VIT_H
#define VIT_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class vit;
}

class vit : public QDialog
{
    Q_OBJECT

public:
    explicit vit(QWidget *parent = nullptr);
    ~vit();
    Ui::vit *ui;

public slots:
    void boutonOk(); // Slot pour gérer l'acceptation de la boîte de dialogue

};

#endif // VIT_H
