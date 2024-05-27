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
    void setSpine(int);
    int valueSpine();

public slots:
    void handleButtonBoxAccepted();

private:
    Ui::vit *ui;
};

#endif // VIT_H
