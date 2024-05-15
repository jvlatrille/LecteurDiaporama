#ifndef APROPOS_H
#define APROPOS_H

#include <QWidget>

namespace Ui {
class aPropos;
}

class aPropos : public QWidget
{
    Q_OBJECT

public:
    explicit aPropos(QWidget *parent = nullptr);
    ~aPropos();

private:
    Ui::aPropos *ui;
};

#endif // APROPOS_H
