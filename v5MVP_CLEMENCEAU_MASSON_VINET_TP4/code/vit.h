#ifndef VIT_H
#define VIT_H

#include <QDialog>
#include <QDebug>  // Assurez-vous d'inclure ceci pour utiliser qDebug()

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
    void handleButtonBoxAccepted();

};

#endif // VIT_H
