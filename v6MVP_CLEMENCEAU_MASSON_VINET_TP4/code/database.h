#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>


#define DATABASE_NAME "nodenot_bd9"
#define CONNECT_TYPE "QODBC"


class database
{
public:
    database();
    ~database();

    bool ouvrirBD();
    bool fermerBD();
    QSqlDatabase getDatabase() const;
    //void chargerDiaposBD();

private:
    QSqlDatabase maBD;
};

#endif // DATABASE_H
