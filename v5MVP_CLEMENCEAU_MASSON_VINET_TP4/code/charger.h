#ifndef CHARGER_H
#define CHARGER_H

#include <QDialog>

namespace Ui {
class charger;
}

class charger : public QDialog
{
    Q_OBJECT

public:
    explicit charger(QWidget *parent = nullptr);
    ~charger();

private:
    Ui::charger *ui;



};

#endif // CHARGER_H
