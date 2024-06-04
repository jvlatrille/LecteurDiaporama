#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSqlDatabase>

class database
{
public:
    database();
    bool ouvrirBD();
    bool fermerBD();

private:
    QSqlDatabase* maBD;
};

#endif // DATABASE_H
