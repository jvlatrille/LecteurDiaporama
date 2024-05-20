#ifndef APROPOS_H
#define APROPOS_H

#include <QDialog>

namespace Ui {
class AProposDialog;
}

class AProposDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AProposDialog(QWidget *parent = nullptr);
    ~AProposDialog();

private:
    Ui::AProposDialog *ui;
};

#endif // APROPOS_H
