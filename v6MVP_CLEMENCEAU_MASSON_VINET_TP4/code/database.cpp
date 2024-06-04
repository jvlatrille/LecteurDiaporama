#include "database.h"

database::database() {
    // Ré-instanciation de la bd
    maBD = new QSqlDatabase();

    // Essayer d'ouvrir
    if(ouvrirBD()) {qDebug() << "Ouverture réussie";}
    else { qDebug() << "Ouveture ratée"; }
}

bool database::ouvrirBD()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost"); // Nom de l'hôte (par exemple, "localhost")
    db.setDatabaseName("eclemence001"); // Nom de la base de données
    db.setUserName("root"); // Nom d'utilisateur
    db.setPassword(""); // Mot de passe

    if(!maBD->open()){
        qDebug() << "Erreur lors de l'ouverture ";
        return false;
    }
    return true;
}

bool database::fermerBD()
{
    maBD->close();
}
