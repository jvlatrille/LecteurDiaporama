#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>


#define DATABASE_NAME "jvlatrille_bd"
#define CONNECT_TYPE "QODBC"


class database
{
public:
    database();
    ~database();

    bool ouvrirBD();
    bool fermerBD();
    //void chargerDiaposBD();

private:
    QSqlDatabase maBD;
};

#endif // DATABASE_H
