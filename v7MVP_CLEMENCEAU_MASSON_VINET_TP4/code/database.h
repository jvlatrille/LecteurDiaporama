#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "QSqlError"


#define DATABASE_NAME "nodenot_bd9"
#define CONNECT_TYPE "QODBC"


class database
{
public:
    database(); // Constructeur
    ~database(); // Destructeur

    bool ouvrirBD(); // Ouvre la connexion à la base de données
    bool fermerBD(); // Ferme la connexion à la base de données

    //Getter
    QSqlDatabase getDatabase() const; // Récupère l'objet base de données

private:
    QSqlDatabase maBD;
};

#endif // DATABASE_H
