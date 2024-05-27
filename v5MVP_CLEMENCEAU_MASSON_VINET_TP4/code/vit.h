#ifndef VIT_H
#define VIT_H

#include <QDialog>

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

private:
    Ui::vit *ui;
};

#endif // VIT_H
