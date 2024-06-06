#ifndef APROPOS_H
#define APROPOS_H

#include <QDialog>

namespace Ui {
class apropos;
}

class apropos : public QDialog
{
    Q_OBJECT

public:
    explicit apropos(QWidget *parent = nullptr);
    ~apropos();

private:
    Ui::apropos *ui;
};

#endif // APROPOS_H
